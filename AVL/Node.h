/*************************************************************
* Author:		Justin.Urbany
* Filename:		Node.h
* Date Created:	1/19/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#ifndef NODE_H
#define NODE_H

template<typename T>
class BinaryTree;
template<typename T>
class List;
/************************************************************************
* Class: Node
*
* Purpose: Creates a Node that holds pointers to other Nodes and any type
*		of data it wants used for linked lists
*
* Manager functions:
* 	Node ( )
*			make a node with no data
*	Node (T data)
*		Make a node with passed in data
*	Node (const Node & copy)
*		create a copy of a Node
*	operator = (const Node & copy)
*		copy over all the data of one Node into a new Node
*	~Node()
*		Delete the Node
*
*************************************************************************/
template<typename T>
class Node
{
	friend BinaryTree<T>;
	friend List<T>;
public:
	enum balance { RIGHTB = -1, EQUAL, LEFTB };
	Node();
	Node(T Data);
	int GetBalance();
	void SetBalance(balance nbalance);
	Node(const Node & copy);
	Node & operator =(const Node & rhs);
	void SetData(T data);
	T GetData();
	void SetLeft(Node<T> * left);
	void SetRight(Node<T> * right);
	Node<T> *& GetRight();
	Node<T> *& GetLeft();
	~Node();
private:
	balance nodebalance;

	T	m_Data;
	Node * m_right;
	Node * m_left;
};


#endif
/**********************************************************************
* Purpose: Create an empty Node
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
template<typename T>
inline Node<T>::Node() :m_right(nullptr), m_left(nullptr), nodebalance(EQUAL)
{
}
/**********************************************************************
* Purpose: Create a Node with specified Data
*
* Precondtion: pass in the Data
*
* Postcondition: None
*
************************************************************************/
template<typename T>
inline Node<T>::Node(T Data) : m_Data(Data), m_right(nullptr), m_left(nullptr), nodebalance(EQUAL)
{
}
/**********************************************************************
* Purpose: The purpose of this function is to get the balance factor
*			for a node
*
* Precondition: The node must exist
*
* Postcondition: The value of the balance factor must be returned as
*		an integer
*
************************************************************************/
template<typename T>
inline int Node<T>::GetBalance()
{
	int height = 0;
	if (nodebalance == RIGHTB)
	{
		height = -1;
	}
	else if (nodebalance == EQUAL)
	{
		height = 0;
	}
	else
	{
		height = 1;
	}
	return height;
}
/**********************************************************************
* Purpose: The purpose of this function is so that a nodes balance factor
*			can be set if it ever changes
*
* Precondition:	The new balance factor must be passed in
*
* Postcondition: the nodes balance factor is the passed in balance factor
*
************************************************************************/
template<typename T>
inline void Node<T>::SetBalance(balance nbalance)
{
	nodebalance = nbalance;
}
/**********************************************************************
* Purpose: Create Copy of a node
*
* Precondtion: Pass in a node
*
* Postcondition: calling Node is equal to the passed in Node
*
************************************************************************/
template<typename T>
inline Node<T>::Node(const Node & copy)
{
	*this = copy;
}
/**********************************************************************
* Purpose: Assign one Node to be another Node
*
* Precondtion: pass in a Node object
*
* Postcondition: Copied over all Data and made the nodes eqaul returned
*				the value of the modified node object
*
************************************************************************/
template<typename T>
inline Node<T> & Node<T>::operator=(const Node & rhs)
{
	if (this != &rhs)
	{
		*this = nullptr;
		if (rhs != nullptr)
		{
			m_Data = rhs.m_Data;
			m_right = rhs.m_right;
			m_left = rhs.m_left;
		}
	}
	return *this;
}
/**********************************************************************
* Purpose: The purpose of this function is so that a Nodes data can
*		be set by the data that is passed in
*
* Precondition: Data must be passed in
*
* Postcondition: The Nodes m_data must be set to the passed in data
*
************************************************************************/
template<typename T>
inline void Node<T>::SetData(T data)
{
	m_Data = data;
}
/**********************************************************************
* Purpose: The purpose of this function is to get a Nodes current data
*	and return that current data
*
* Precondition: The GetData funcition must be called from a node object
*
* Postcondition: the value of the m_data memember must be returned
*
************************************************************************/
template<typename T>
inline T Node<T>::GetData()
{
	return m_Data;
}
/**********************************************************************
* Purpose: The purpsoe of this function is to be able to set a Nodes
*			left Node pointer
*
* Precondition: Must pass in a node pointer
*
* Postcondition: the passed in node pointer must be assigned to the Nodes
*				left
*
************************************************************************/
template<typename T>
inline void Node<T>::SetLeft(Node<T>* left)
{
	m_left = left;
}
/**********************************************************************
* Purpose: The purpose of this fucntion is to set a nodes right pointer
*
* Precondition: must pass in a node pointer
*
* Postcondition: the passed in node pointer must be set to the calling nodes
*		right node pointer
*
************************************************************************/
template<typename T>
inline void Node<T>::SetRight(Node<T>* right)
{
	m_right = right;
}
/**********************************************************************
* Purpose: The purpose of this function is to return a nodes right
*			node pointer
*
* Precondition: Must be called from a node object
*
* Postcondition: A node right pointer is returned
*
************************************************************************/
template<typename T>
inline Node<T> *& Node<T>::GetRight()
{
	return m_right;
}
/**********************************************************************
* Purpose: The purpose of this function it to get a node left node pointer
*
* Precondition: Must be caled from a node object
*
* Postcondition: A node left pointer is returned
*
************************************************************************/
template<typename T>
inline Node<T> *& Node<T>::GetLeft()
{
	return m_left;
}

/**********************************************************************
* Purpose: Delete a Node
*
* Precondtion: None
*
* Postcondition: m_next and m_Previous are null ptr
*
************************************************************************/
template<typename T>
inline Node<T>::~Node()
{
	m_left = nullptr;
	m_right = nullptr;
}
