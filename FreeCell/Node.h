/*************************************************************
* Author:		Justin.Urbany
* Filename:		Node.h
* Date Created:	1/19/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#ifndef NODE_H
#define NODE_H

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
	friend List<T>;
public:

	Node(const Node & copy);
	Node & operator =(const Node & rhs);
	~Node();
private:

	Node();
	Node(T Data);
	T	m_Data;
	Node * m_Next;
	Node * m_Previous;
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
inline Node<T>::Node() :m_Next(nullptr), m_Previous(nullptr)
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
inline Node<T>::Node(T Data) : m_Data(Data), m_Next(nullptr), m_Previous(nullptr)
{
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
		m_Data = rhs.m_Data;
		m_Next = rhs.m_Next;
		m_Previous = rhs.m_Previous;
	}
	return *this;
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
	m_Next = nullptr;
	m_Previous = nullptr;
}