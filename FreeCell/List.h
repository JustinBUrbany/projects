/*************************************************************
* Author:		Justin.Urbany
* Filename:		List.h
* Date Created:	1/19/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#ifndef LIST_H
#define LIST_H
#include "Node.h"
/************************************************************************
* Class: List
*
* Purpose: Create A doubly linked list
*
* Manager functions:
* 	List ( )
* 		set Head and Tail to Nullptr
*	~List ()
*		Purge the list and set to nullptr
*	List (const List & copy)
*		create a copy of a list
*	operator = (const List & copy)
*		copy over all the data of one list into a new list
*
* Methods:
*	isEmpty();
*		Checks if list is empty
*	First()
*		get the data at the first element
*	Last()
*		get the data at the last element
*	Prepend()
*		add data to the front of list
*	Append()
*		add data to the end of list
*	Purge()
*		delete each node in the list
*	RemoveLast(0
*		delete the last element of the list
*************************************************************************/
template<typename T>
class List
{
public:
	List();
	List(const List & copy);
	~List();
	List & operator =(const List & rhs);
	bool isEmpty();
	const T & First();
	const T & Last();
	void Prepend(T data);
	void Append(T data);
	void Purge();
	void RemoveLast();
private:
	Node<T> * m_Head;
	Node<T> * m_Tail;
};
/**********************************************************************
* Purpose: Create a List
*
* Precondtion: None
*
* Postcondition: List is nullptr
*
************************************************************************/
template<typename T>
inline List<T>::List() : m_Head(nullptr), m_Tail(nullptr)
{
}
/**********************************************************************
* Purpose: Copy one list to another List
*
* Precondtion: Take in a passed in list
*
* Postcondition: Both List same
*
************************************************************************/
template<typename T>
inline List<T>::List(const List & copy)
{

	*this = copy;
}
/**********************************************************************
* Purpose: Delete list when out of scope
*
* Precondtion: None
*
* Postcondition: List is gone
*
************************************************************************/
template<typename T>
inline List<T>::~List()
{
	Purge();
}
/**********************************************************************
* Purpose: The purpose of this function is to take a list and assign
*			it to another list
*
* Precondtion: Take in a const List<T>
*
* Postcondition:  Have completely copied all data from the passed in list
*					into calling list object
*
************************************************************************/
template<typename T>
inline List<T> & List<T>::operator=(const List<T> & rhs)
{
	if (this != &rhs) //if left hand side is not the same as the rhs
	{
		Node<T> * travel = rhs.m_Head;
		this->Purge();
		while (travel)
		{
			this->Append(travel->m_Data);
			travel = travel->m_Next;
		}

	}

	return *this;
}
/**********************************************************************
* Purpose: Check and See if List is empty returned true if it is empty
*			false if not
*
* Precondtion: none
*
* Postcondition: return true if empty false if not empty
*
************************************************************************/
template<typename T>
inline bool List<T>::isEmpty()
{
	bool empty = true; //bool to hold if lists contains any nodes
	if (m_Head != nullptr)
	{
		empty = false; //if not empty return false
	}
	return empty;
}
/**********************************************************************
* Purpose: Return the data at the first node of the list if it is not
*			empty
*
* Precondtion: None
*
* Postcondition: Returned an exception if empty or the data if wasn't
*
************************************************************************/
template<typename T>
inline const T & List<T>::First()
{
	if (isEmpty())  //if the list isn't empty
		throw Exception("No Data in First list is empty"); //otherwise throw an exception
	return m_Head->m_Data; //return the data at the head node

}
/**********************************************************************
* Purpose: Return the data at the last node of the lsit if it is not
*          empty
*
* Precondtion:
*
* Postcondition: Returned an exception if empty or the data if wasn't
*
************************************************************************/
template<typename T>
inline const T & List<T>::Last()
{
	if (isEmpty())
		throw Exception("No Data in Last list is empty"); //otherwise throw exception that list was empty
	return m_Tail->m_Data; //if list isn't empty return data at tail
}
/**********************************************************************
* Purpose: The purpose is to add a node to the beginning of a list
*
* Precondtion: Take in the Data to be added to the list
*
* Postcondition: have added the Data to a new node which is added to the
*				front of the list
************************************************************************/
template<typename T>
inline void List<T>::Prepend(T data)
{
	Node<T> * NN = new Node<T>(data); //create a new node that holds the data

	if (!isEmpty()) //if list isn't empty
	{
		NN->m_Previous = nullptr; //set the new node previous to nullptr
		NN->m_Next = m_Head; //set the new nodes next to current head
		m_Head->m_Previous = NN; //make the current heads previous the new node
		m_Head = NN; //make the NN the Head
	}
	else //If no nodes currently exists in the list
	{
		m_Head = NN; //Make the Head the new node
		m_Tail = m_Head; //make the Tail the Head
	}

}
/**********************************************************************
* Purpose: The purpose is to add a node to the end of a list
*
* Precondtion: Take in the data that is to be added to the list
*
* Postcondition: Have added the data to a new node and added the node
*				to the list
************************************************************************/
template<typename T>
inline void List<T>::Append(T data)
{
	Node<T> * NN = new Node<T>(data); // make a new node that holds the passed in data

	if (!isEmpty()) //if the list isn't empty
	{
		NN->m_Next = nullptr; // set the next to nll ptr
		NN->m_Previous = m_Tail; //make new nodes previous the tail
		m_Tail->m_Next = NN; // makes tails next the new node
		m_Tail = NN; // make the NN the tail
	}
	else
	{
		m_Head = NN; // make the head the NN
		m_Tail = m_Head; // make the tail the head
	}
}
/**********************************************************************
* Purpose: The purpose is to remove all nodes from list
*
* Precondtion: None
*
* Postcondition: Have taken the list if exsists and deleted all elements
*				and set Tail and Head back to nullptr
************************************************************************/
template<typename T>
inline void List<T>::Purge()
{
	if (m_Head) //if the head exists
	{
		Node<T> * travel = m_Head; // make a travel that starts at the head
		while (travel) //while the travel exists
		{
			m_Head = m_Head->m_Next; // make the head heads next
			delete travel; //delete the old head
			travel = nullptr;
			travel = m_Head; //make travel the new head
		}
		travel = nullptr;
	}
	m_Head = nullptr; //make sure the m_head is nullptr
	m_Tail = nullptr; //make sure the tail is nullptr

}
/**********************************************************************
* Purpose: Remove the last element of the List
*
* Precondtion: None
*
* Postcondition: Have taken the List made it one smaller and deleted
*			the last node in that list
************************************************************************/
template<typename T>
inline void List<T>::RemoveLast()
{
	if (m_Tail != nullptr)
	{
		if (m_Tail == m_Head)
		{
			delete m_Head;
			m_Head = nullptr;
			m_Tail = nullptr;
		}
		else
		{
			Node<T> * temp = m_Tail;
			m_Tail->m_Previous->m_Next = nullptr;
			m_Tail = m_Tail->m_Previous;
			delete temp;
		}
	}
}



#endif LIST_H