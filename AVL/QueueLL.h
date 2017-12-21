/*************************************************************
* Author:		Justin.Urbany
* Filename:		QueueLL.h
* Date Created:	2/10/17
* Modifications:	2/21/17 -Added Comments
**************************************************************/
#ifndef QUEUELL_H
#define QUEUELL_H
#include "List.h"
#include "Exception.h"
/************************************************************************
* Class: QueueLL
*
* Purpose: The purpose of this is to create a Queue that is contained
*			by linked list
*
* Manager functions:
* 	QueueLL ( )
*			make an empty Queue
*	QueueLL(QueueLL & copy)
*		make a copy of a Queue
*	QueueLL (const QueueLL & copy)
*		create a copy of a Node
*	operator = (const QueueLL & copy)
*		copy over all the data of one QueueLL into a new QueueLL
*	~QueueLL()
*		Delete a QueueLL
*
*************************************************************************/
template<typename T>
class QueueLL
{
public:
	QueueLL();
	QueueLL(QueueLL & copy);
	~QueueLL();
	QueueLL & operator=(QueueLL & rhs);

	int Size();
	bool isEmpty();
	void Engueue(T data);
	T Dequeue();
	T & Front();

private:
	int m_current_items;
	List<T> m_queue;
};


#endif
/**********************************************************************
* Purpose: Create an empty QueueLL
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
template<typename T>
inline QueueLL<T>::QueueLL() :m_current_items(-1)
{
}
/**********************************************************************
* Purpose: Copy a QueueLL
*
* Precondtion: passed in the one to make copy of
*
* Postcondition: both QueueLL are the same
*
************************************************************************/
template<typename T>
inline QueueLL<T>::QueueLL(QueueLL & copy)
{
	*this = copy;

}
/**********************************************************************
* Purpose: Delete a QueueLL
*
* Precondtion: Called when the QueueLL is going out of scope
*
* Postcondition: The QueueLL is gone
*
************************************************************************/
template<typename T>
inline QueueLL<T>::~QueueLL()
{
	m_current_items = 0;
}
/**********************************************************************
* Purpose: The purpose of this is to be able to assigned one queue to
*			another queue
*
* Precondtion: Pass in the queue that is the assignee
*
* Postcondition: Both queue are the same
*
************************************************************************/
template<typename T>
inline QueueLL<T> & QueueLL<T>::operator=(QueueLL & rhs)
{
	m_current_items = rhs.m_current_items;
	m_queue = rhs.m_queue;
	return *this;
}
/**********************************************************************
* Purpose: This returns the number of items currently inside the queue
*
* Precondtion: Called from a queue
*
* Postcondition: Size of the queue is returned
*
************************************************************************/
template<typename T>
inline int QueueLL<T>::Size()
{
	return m_current_items + 1;
}
/**********************************************************************
* Purpose: Checks to see if a queue is empty
*
* Precondtion: Called from a queue
*
* Postcondition: returns true if the queue is empty else returns false
*
************************************************************************/
template<typename T>
inline bool QueueLL<T>::isEmpty()
{
	bool empty = false;
	if (m_current_items < 0)
	{
		empty = true;
	}
	return empty;
}
/**********************************************************************
* Purpose: Puts an item at the end of a queue
*
* Precondtion: Takes in the data that is going to be place in the queue
*
* Postcondition: The queue is one bigger
*
************************************************************************/
template<typename T>
inline void QueueLL<T>::Engueue(T data)
{

	m_queue.Append(data);
	m_current_items++;
}
/**********************************************************************
* Purpose: Takes the front piece of data off of the queue
*
* Precondtion: Must have a queue with size greater then zero
*
* Postcondition: Returns the value of the first piece of data on the queue
*				size of queue is deremented 1
*
************************************************************************/
template<typename T>
inline T QueueLL<T>::Dequeue()
{
	if (isEmpty())
		throw Exception("Queue is empty");
	m_current_items--;
	T temp = m_queue.First();
	m_queue.RemoveFirst();

	return temp;

}
/**********************************************************************
* Purpose: The purpose of this fucntion is to check and see the value
*			that is at the front of the queue
*
* Precondtion: Called from a queue with size greater then zero
*
* Postcondition: Return the value of the data at the front of the que
*
************************************************************************/
template<typename T>
inline T & QueueLL<T>::Front()
{
	if (isEmpty())
		throw Exception("Queue is empty");
	T temp = m_queue.First();
	return temp;
}

