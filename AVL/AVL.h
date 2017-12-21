/*************************************************************
* Author:		Justin.Urbany
* Filename:		Exception.h
* Date Created:	1/23/17
* Modifications:	1/24/17-added comments
**************************************************************/
#ifndef AVL_H
#define AVL_H
#include "BinarySearchTree.h"
/************************************************************************
* Class: AVL
*
* Purpose: To add rebalancing factor to a Binary Search Tree
*
* Manager functions:
* 	AVL ( )
*	AVL (AVL & copy)
*	operator = ( AVL & copy)
*		set one Exception equal to the other ExceptionA
*	~AVL()
*		clear memory from AVL
*
* Methods:
*	
*************************************************************************/
template<typename T>
class AVL : BinaryTree<T>
{
public:
	AVL();
	AVL(AVL & copy);
	~AVL();
	AVL & operator =(AVL & rhs);
	void Insert(T data);
	void Print(void(*Visit)(T));
	void Delete(T data);

private:
	void Insert(Node<T> *& root, T data, bool & taller);
	void Delete(Node<T> *& root, T data, bool & smaller, bool & success);
	void DeleteRB(Node<T> *&root, bool & smaller);
	void DeleteLB(Node<T> *&root, bool & smaller);
	void RightBalance(Node<T> * & root, bool & taller);
	void LeftBalance(Node<T> * & root, bool & taller);
	void RightRotate(Node<T> *& root);
	void LeftRotate(Node<T> *& root);
};
#endif
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline AVL<T>::AVL()
{
	BinaryTree();
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline AVL<T>::AVL(AVL & copy)
{
	*this = copy;
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline AVL<T>::~AVL()
{

}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline AVL<T> & AVL<T>::operator=(AVL & rhs)
{
	if (this != &rhs)
	{
		Purge();
		m_root = nullptr;
		if (!rhs.isEmpty())
		{
			Node<T> * current = rhs.m_root;
			QueueLL<Node<T>*> equalque;
			//Do Breath-First traversal With an Insert instead of Print statement
			while (current != nullptr)
			{
				Insert(current->GetData());

				if (current->GetLeft() != nullptr)
				{
					equalque.Engueue(current->GetLeft());
				}
				if (current->GetRight() != nullptr)
				{
					equalque.Engueue(current->GetRight());
				}

				if (!equalque.isEmpty())
				{
					current = equalque.Front();
					equalque.Dequeue();
				}
				else
				{
					current = nullptr;
				}
			}
		}
	}
	return *this;
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::Insert(T data)
{
	bool taller = false;
	Insert(m_root, data, taller);
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::Print(void(*Visit)(T))
{
	Breath_First_Traversal(Visit);
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::Delete(T data)
{
	bool smaller = false;
	bool success = false;
	Delete(m_root, data, smaller, success);
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::Insert(Node<T>*& root, T data, bool & taller)
{
	if (!root)
	{
		root = new Node<T>(data);
		taller = true;
	}
	else if (data < root->GetData())
	{
		Insert(root->GetLeft(), data, taller);
		if (taller)
		{
			switch (root->GetBalance())
			{
			case 1: //Was 1 so now is 2
				LeftBalance(root, taller);
				break;
			case 0: //Was equal so now is 1
				root->SetBalance(root->LEFTB);
				break;
			case -1:
				root->SetBalance(root->EQUAL);
				taller = false;
				break;
			}
		}
	}
	else
	{
		Insert(root->GetRight(), data, taller);
		{
			if (taller)
			{
				switch (root->GetBalance())
				{
				case -1://now -2
					RightBalance(root, taller);
					break;
				case 0:
					root->SetBalance(root->RIGHTB);
					break;
				case 1:
					root->SetBalance(root->EQUAL);
					taller = false;
					break;
				}
			}
		}
	}
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::Delete(Node<T>*& root, T data, bool & smaller, bool & success)
{
	Node<T> * dltPtr=nullptr;
	Node<T> *exchPtr=nullptr;
	Node<T> *newRoot=nullptr;
	if (!root)
	{
		throw Exception("The node wasn't in your tree");
		smaller = false;
		success = false;
	}
	if (root->GetData() > data)
	{
		Delete(root->GetLeft(), data, smaller, success);
		if (smaller)
		{
			DeleteRB(root, smaller);
		}

	}
	else if (root->GetData() < data)
	{
		Delete(root->GetRight(), data, smaller, success);
		if (smaller)
		{
			DeleteLB(root, smaller);
		}
	}
	else
	{
		dltPtr = root;
		if (!root->GetRight())
		{
			newRoot = root->GetLeft();
			success = true;
			smaller = true;
			delete(dltPtr);
			dltPtr = nullptr;
			root = newRoot;
		}
		else
		{
			if (!root->GetLeft())
			{
				newRoot = root->GetRight();
				success = true;
				smaller = true;
				delete(dltPtr);
				dltPtr = nullptr;
				root = newRoot;
			}
			else
			{
				exchPtr = root->GetLeft();
				while (exchPtr->GetRight())
				{
					exchPtr = exchPtr->GetRight();
				}

				root->SetData(exchPtr->GetData());

				Delete(root->GetLeft(), exchPtr->GetData(), smaller, success);
				if (smaller)
					DeleteRB(root, smaller);
			}
		}
	}
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::DeleteRB(Node<T>*& root, bool & smaller)
{
	Node<T> * rightTree;
	Node<T> * leftTree;
	switch (root->GetBalance())
	{
	case 1:
		root->SetBalance(Node<T>::EQUAL);
		break;
	case 0:
		root->SetBalance(Node<T>::RIGHTB);		
		smaller = false;
		break;
	case -1:
		rightTree = root->GetRight();
		if (rightTree->GetBalance() == 1)
		{
			leftTree = rightTree->GetLeft();
			switch (leftTree->GetBalance())
			{
			case 1:
				rightTree->SetBalance(Node<T>::RIGHTB);
				root->SetBalance(Node<T>::EQUAL);
				break;
			case 0:
				root->SetBalance(Node<T>::EQUAL);
				rightTree->SetBalance(Node<T>::EQUAL);
				break;
			case -1:
				root->SetBalance(Node<T>::LEFTB);
				rightTree->SetBalance(Node<T>::EQUAL);
				break;
			}
			leftTree->SetBalance(Node<T>::EQUAL);
			LeftRotate(rightTree);
			RightRotate(root);
		}
		else
		{
			switch (rightTree->GetBalance())
			{
			case 1:
				break;
			case -1:
				root->SetBalance(Node<T>::EQUAL);
				rightTree->SetBalance(Node<T>::EQUAL);
				break;
			case 0:
				root->SetBalance(Node<T>::RIGHTB);
				rightTree->SetBalance(Node<T>::LEFTB);
				smaller = false;
				break;
			}
			RightRotate(root);
		}
	}
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::DeleteLB(Node<T>*& root, bool & smaller)
{
	Node<T> * rightTree;
	Node<T> * leftTree;
	switch (root->GetBalance())
	{
	case -1:
		root->SetBalance(Node<T>::EQUAL);
		break;
	case 0:
		root->SetBalance(Node<T>::LEFTB);
		smaller = false;
		break;
	case 1:
		leftTree = root->GetLeft();
		if (leftTree->GetBalance() == -1)
		{
			rightTree = leftTree->GetRight();
			switch (rightTree->GetBalance())
			{
			case -1:
				leftTree->SetBalance(Node<T>::LEFTB);
				root->SetBalance(Node<T>::EQUAL);
				break;
			case 0:
				root->SetBalance(Node<T>::EQUAL);
				leftTree->SetBalance(Node<T>::EQUAL);
				break;
			case 1:
				root->SetBalance(Node<T>::RIGHTB);
				leftTree->SetBalance(Node<T>::EQUAL);
				break;
			}
			rightTree->SetBalance(Node<T>::EQUAL);
			RightRotate(leftTree);
			LeftRotate(root);
		}
		else
		{
			switch (leftTree->GetBalance())
			{
			case -1:
				break;
			case 1:
				root->SetBalance(Node<T>::EQUAL);
				leftTree->SetBalance(Node<T>::EQUAL);
				break;
			case 0:
				root->SetBalance(Node<T>::LEFTB);
				leftTree->SetBalance(Node<T>::RIGHTB);
				smaller = false;
				break;
			}
			LeftRotate(root);
		}
	}
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::RightBalance(Node<T> * & root, bool & taller)
{
	Node<T> * leftTree;
	Node<T> * rightTree = root->GetRight();

	switch (rightTree->GetBalance())
	{
	case -1: /// This will Be the RR 
		root->SetBalance(Node<T>::EQUAL);
		rightTree->SetBalance(Node<T>::EQUAL);
		RightRotate(root);
		taller = false;
		break;
	case 0:
		//This is an Eroor
		break;
	case 1: //This is going to be the LR rotation
		leftTree = rightTree->GetLeft();
		switch (leftTree->GetBalance())
		{
		case -1:
			root->SetBalance(Node<T>::LEFTB);
			rightTree->SetBalance(Node<T>::EQUAL);
			break;
		case 0:
			root->SetBalance(Node<T>::EQUAL);
			rightTree->SetBalance(Node<T>::EQUAL);
			break;
		case 1:
			root->SetBalance(Node<T>::EQUAL);
			rightTree->SetBalance(Node<T>::RIGHTB);
			break;
		}
		leftTree->SetBalance(Node<T>::EQUAL);

		LeftRotate(rightTree);
		root->SetRight(rightTree);
		RightRotate(root);
		taller = false;
		break;
	}




	//int nheight = 0;
	//int rheight = 0;
	//int leftheight = 0;


	//if (root->GetRight()->GetBalance() == 1)
	//{
	//	LeftRotate(root->GetRight());
	//}

	//RightRotate(root);

	//rheight = Height(root->GetRight()); //problem is the new child
	//leftheight = Height(root->GetLeft());// root is the new root
	//nheight = leftheight - rheight;

	//if (nheight == -1)
	//{
	//	root->SetBalance(root->RIGHTB);
	//}
	//else if (nheight == 0)
	//{
	//	root->SetBalance(root->EQUAL);
	//}
	//else
	//{
	//	root->SetBalance(root->LEFTB);
	//}

	//rheight = Height(root->GetLeft()->GetRight());
	//leftheight = Height(root->GetLeft()->GetLeft());
	//nheight = leftheight - rheight;

	//if (nheight == -1)
	//{
	//	root->GetLeft()->SetBalance(root->RIGHTB);
	//}
	//else if (nheight == 0)
	//{
	//	root->GetLeft()->SetBalance(root->EQUAL);
	//}
	//else
	//{
	//	root->GetLeft()->SetBalance(root->LEFTB);
	//}

	//taller = false;

}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::LeftBalance(Node<T> * & root, bool & taller)
{
	Node<T> *rightTree;
	Node<T> *leftTree=root->GetLeft();

	switch (leftTree->GetBalance())
	{
	case 1://This is an LL so set the root and root of problem Balance to 0 then rotate left to rebalance
		root->SetBalance(Node<T>::EQUAL);//going to rotate so set new balance
		leftTree->SetBalance(Node<T>::EQUAL);//going to rotate so set new balance
		LeftRotate(root);//Do the Left rotate
		taller = false; //Reset taller since you did the rotation
		break;
	case 0://This is an error
		break;
	case -1: // This is going nto be our LR rotation so need to do both but do right first on lefts right child
		rightTree = leftTree->GetRight();
		switch (rightTree->GetBalance())
		{
		case 1:
			root->SetBalance(Node<T>::RIGHTB);
			leftTree->SetBalance(Node<T>::EQUAL);
			break;
		case 0:
			root->SetBalance(Node<T>::EQUAL);
			leftTree->SetBalance(Node<T>::EQUAL);
			break;
		case -1:
			root->SetBalance(Node<T>::EQUAL);
			leftTree->SetBalance(Node<T>::LEFTB);
			break;
		}

		rightTree->SetBalance(Node<T>::EQUAL);
		RightRotate(leftTree);
		root->SetLeft(leftTree);
		LeftRotate(root);
		taller = false;
		break;
	}



	//rheight = Height(problem->GetRight());
	//leftheight = Height(problem->GetLeft());
	//nheight = leftheight - rheight;

	//int nheight = 0;
	//int rheight = 0;
	//int leftheight = 0;

	//if (root->GetLeft()->GetBalance() == -1)
	//{
	//	RightRotate(root->GetLeft());
	//}

	//LeftRotate(root);
	//rheight = Height(root->GetRight());
	//leftheight = Height(root->GetLeft());
	//nheight = leftheight - rheight;
	//if (nheight == -1)
	//{
	//	root->SetBalance(root->RIGHTB);
	//}
	//else if (nheight == 0)
	//{
	//	root->SetBalance(root->EQUAL);
	//}
	//else
	//{
	//	root->SetBalance(root->LEFTB);
	//}

	//rheight = Height(root->GetRight()->GetRight());
	//leftheight = Height(root->GetRight()->GetLeft());
	//nheight = leftheight - rheight;
	//if (nheight == -1)
	//{
	//	root->GetRight()->SetBalance(root->RIGHTB);
	//}
	//else if (nheight == 0)
	//{
	//	root->GetRight()->SetBalance(root->EQUAL);
	//}
	//else
	//{
	//	root->GetRight()->SetBalance(root->LEFTB);
	//}

	//taller = false;

}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::RightRotate(Node<T>*& root)
{
	Node<T> * problem = root;
	root = root->GetRight(); //Set the root of the problem to the new root
	problem->GetRight() = root->GetLeft();// set root problems left child to old roots right
	root->GetLeft() = problem; // set old root to new roots left
}
/**********************************************************************
* Purpose:
*
* Precondtion:
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void AVL<T>::LeftRotate(Node<T>*& root)
{
	Node<T> * problem = root;
	root = root->GetLeft();
	problem->GetLeft() = root->GetRight();
	root->GetRight() = problem;
}
