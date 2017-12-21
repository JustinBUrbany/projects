/*************************************************************
* Author:		Justin.Urbany
* Filename:		Exception.h
* Date Created:	1/23/17
* Modifications:	1/24/17-added comments
**************************************************************/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Exception.h"
#include "QueueLL.h"
/************************************************************************
* Class: Exception
*
* Purpose: Creates a character message to throw to user when error occurs
*
* Manager functions:
* 	Exception ( )
*	Exception (char * msg)
*		Create exception allocate space and intialize message
*	Exception (const Exception & copy)
*		Create a copy of an exceptinA
*	operator = (const Exception & copy)
*		set one Exception equal to the other ExceptionA
*	~Exception()
*		clear memory for the Exception
*
* Methods:
*	const char * getMessage() returns the current message in the exception
*	void setMessage(char * msg) set the current message in the exception
*************************************************************************/
template<typename T>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(BinaryTree & copy);
	~BinaryTree();
	BinaryTree & operator =(BinaryTree & rhs);

	void Insert(T data);
	void Delete(T data);
	void Purge();
	int Height();
	void In_Order_Traversal(void(*visit)(T));
	void Pre_Order_Traversal(void(*visit)(T));
	void Post_Order_Traversal(void(*visit)(T));
	void Breath_First_Traversal(void(*Visit)(T));
	bool isEmpty();

protected:
	Node<T> * m_root;
	void Pre_Order_Traversal(void(*visit)(T), Node<T> * current);
	void Post_Order_Traversal(void(*visit)(T), Node<T> * current);
	void In_Order_Traversal(void(*visit)(T), Node<T> * current);
	int Height(Node<T> * node);
	void Insert(Node<T> *& root, T data);
	void DeleteRecursive(Node<T> *& root, T data);
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
inline BinaryTree<T>::BinaryTree() : m_root(nullptr)
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
inline BinaryTree<T>::BinaryTree(BinaryTree & copy)
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
inline BinaryTree<T>::~BinaryTree()
{
	Purge();
	m_root = nullptr;
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
inline BinaryTree<T> & BinaryTree<T>::operator=(BinaryTree & rhs)
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
				Insert(current->m_Data);

				if (current->m_left != nullptr)
				{
					equalque.Engueue(current->m_left);
				}
				if (current->m_right != nullptr)
				{
					equalque.Engueue(current->m_right);
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
inline void BinaryTree<T>::Insert(T data)
{
	Insert(m_root, data);
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
inline void BinaryTree<T>::Insert(Node<T> *& root, T data)
{
	if (root == nullptr)
	{
		Node<T> * nn = new Node<T>(data);
		root = nn;
	}
	else if (root->m_Data > data)
	{
		Insert(root->m_left, data);
	}
	else
	{
		Insert(root->m_right, data);
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
inline void BinaryTree<T>::DeleteRecursive(Node<T>*& root, T data)
{
	Node<T> * node = nullptr;

	if (m_root == nullptr)
	{
		throw Exception("Can't delete from an empty list.");
	}
	else if (root == nullptr)
	{
		throw Exception("Node you were trying to delete doesn't exsits");
	}
	else if (root->m_Data == data)
	{
		if (root->m_left != nullptr && root->m_right != nullptr)
		{
			Node<T> * previous = root;
			Node<T> * Child = root->m_left;
			while (Child->m_right != nullptr)
			{
				previous = Child;
				Child = Child->m_right;
			}
			if (previous->m_left == root->m_left)
			{
				previous->m_left = Child->m_left;
				Child->m_left = nullptr;
				Child->m_right = nullptr;
				delete Child;
				Child = nullptr;
			}
			else
			{
				root->m_Data = Child->m_Data;
				previous->m_right = Child->m_left;
				Child->m_right = nullptr;
				Child->m_left = nullptr;
				delete Child;
				Child = nullptr;
			}
		}
		else if (root->m_left == nullptr && root->m_right != nullptr)
		{
			root->m_Data = root->m_right->m_Data;
			node = root->m_right;
			root->m_left = node->m_left;
			root->m_right = node->m_right;
			node->m_right = nullptr;
			node->m_left = nullptr;
			delete node;
			node = nullptr;
		}
		else if (root->m_left != nullptr && root->m_right == nullptr)
		{
			root->m_Data = root->m_left->m_Data;
			node = root->m_left;
			root->m_left = node->m_left;
			root->m_right = node->m_right;
			node->m_left = nullptr;
			node->m_right = nullptr;
			delete node;
			node = nullptr;
		}
		else
		{
			delete root;
			root = nullptr;
		}
	}
	else
	{
		if (root->m_Data > data)
		{
			DeleteRecursive(root->m_left, data);
		}
		else
		{
			DeleteRecursive(root->m_right, data);
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
inline void BinaryTree<T>::Delete(T data)
{
	DeleteRecursive(m_root, data);
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
inline void BinaryTree<T>::Purge()
{
	if (m_root != nullptr)
	{
		while (m_root->m_left != nullptr || m_root->m_right != nullptr)
		{
			if (m_root->m_left != nullptr)
			{
				DeleteRecursive(m_root->m_left, m_root->m_left->m_Data);
			}
			if (m_root->m_right != nullptr)
			{
				DeleteRecursive(m_root->m_right, m_root->m_right->m_Data);
			}
		}
		DeleteRecursive(m_root, m_root->m_Data);
		m_root = nullptr;
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
inline int BinaryTree<T>::Height()
{

	return (Height(m_root) - 1);
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
inline int BinaryTree<T>::Height(Node<T>* node)
{
	int lheight = 1;
	int rheight = 1;
	if (node != nullptr)
	{
		if (node->GetLeft() != nullptr)
		{
			lheight += Height(node->m_left);
		}
		if (node->GetRight() != nullptr)
		{
			rheight += Height(node->m_right);
		}
		if (lheight > rheight)
		{
			rheight = lheight;
		}
	}
	else
	{
		rheight = 0;
	}

	return rheight;
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
inline void BinaryTree<T>::In_Order_Traversal(void(*visit)(T))
{
	In_Order_Traversal(visit, m_root);
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
inline void BinaryTree<T>::In_Order_Traversal(void(*visit)(T), Node<T> * current)
{
	if (current != nullptr)
	{
		In_Order_Traversal(visit, current->m_left);
		visit(current->m_Data);
		In_Order_Traversal(visit, current->m_right);
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
inline void BinaryTree<T>::Pre_Order_Traversal(void(*visit)(T))
{
	Pre_Order_Traversal(visit, m_root);
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
inline void BinaryTree<T>::Pre_Order_Traversal(void(*visit)(T), Node<T>* current)
{
	if (current != nullptr)
	{
		visit(current->m_Data);
		Pre_Order_Traversal(visit, current->m_left);
		Pre_Order_Traversal(visit, current->m_right);
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
inline void BinaryTree<T>::Post_Order_Traversal(void(*visit)(T))
{
	Post_Order_Traversal(visit, m_root);
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
inline void BinaryTree<T>::Post_Order_Traversal(void(*visit)(T), Node<T>* current)
{
	if (current != nullptr)
	{
		Post_Order_Traversal(visit, current->m_left);
		Post_Order_Traversal(visit, current->m_right);
		visit(current->m_Data);
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
inline void BinaryTree<T>::Breath_First_Traversal(void(*visit)(T))
{
	QueueLL<Node<T>*> Breath_que;
	Node<T> * current = m_root;

	while (current != nullptr)
	{
		visit(current->m_Data);

		if (current->m_left != nullptr)
		{
			Breath_que.Engueue(current->m_left);
		}

		if (current->m_right != nullptr)
		{
			Breath_que.Engueue(current->m_right);
		}

		if (!Breath_que.isEmpty())
		{
			current = Breath_que.Front();
			Breath_que.Dequeue();
		}
		else
		{
			current = nullptr;
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
inline bool BinaryTree<T>::isEmpty()
{
	bool empty = false;
	if (m_root == nullptr)
	{
		empty = true;
	}
	return empty;
}

