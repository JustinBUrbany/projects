/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stackll.h
* Date Created:	2/4/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#ifndef STACKLL_H
#define STACKLL_H
#include "List.h"
#include "Exception.h"
/************************************************************************
* Class: Stackll
*
* Purpose: Create a Stack with a linked list  of any type
*
* Manager functions:
* 	Stackll ()
* 		Create a Stackll with intialize size 0
*	~Stack()
*		Delete the stack and reset its length to zero
*
* Methods:
*	int Size()
*		Returns current size of Stack
*	Push(T & data)
*		puts data on top of the stack
*   const T & Peek()
*		returns data at the top of the stack
*	const T & Pop()
*		returns data at the top of the stack and removes that data from the top of stack
*   bool isEmpty()
*		Returns if the stack is Empty or Not
*************************************************************************/
template<typename T>
class Stackll
{
public:
	Stackll();
	~Stackll();
	int Size();
	void Push(T & data);
	const T & Peek();
	const T & Pop();
	bool isEmpty();

private:
	List<T> m_stack;
	int m_size;

};

#endif
/**********************************************************************
* Purpose: Create a Stack
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
template<typename T>
inline Stackll<T>::Stackll() : m_size(-1)
{
}
/**********************************************************************
* Purpose: Delete a Stack
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
template<typename T>
inline Stackll<T>::~Stackll()
{
	m_size = -1;
}
/**********************************************************************
* Purpose: Return the Size of the current Stack
*
* Precondtion: None
*
* Postcondition: Returns an integer equal to the size of the stack
*
************************************************************************/
template<typename T>
inline int Stackll<T>::Size()
{
	return m_size + 1;
}
/**********************************************************************
* Purpose: The purpose is to add a piece of Data to the top of your stack
*
* Precondtion: Take in data and add it to the stack make the stack bigger
*
* Postcondition: None
*
************************************************************************/
template<typename T>
inline void Stackll<T>::Push(T & data)
{
	m_stack.Append(data);
	m_size++;
}
/**********************************************************************
* Purpose: Return the Data at the top of stack without removing it if
*			stack is not empty
*
* Precondtion: None
*
* Postcondition: Returns the data at top of stack
*
************************************************************************/
template<typename T>
inline const T & Stackll<T>::Peek()
{
	if (isEmpty())
		throw Exception("Nothing on the stack");
	return m_stack.Last();
}
/**********************************************************************
* Purpose: Return the Data at the top of stack with removing it if
*			stack is not empty
*
* Precondtion: None
*
* Postcondition: Stack is smaller data is returned form top of stack
*
************************************************************************/
template<typename T>
inline const T & Stackll<T>::Pop()
{
	if (isEmpty())
		throw Exception("Nothing is on stack");

	T temp = m_stack.Last();
	m_size--;
	m_stack.RemoveLast();

	return temp;
}
/**********************************************************************
* Purpose: The purpose of this function is to check if the stack is
*		empty
*
* Precondtion:
*
* Postcondition: Return true if stack is empty otherwise return false
*
************************************************************************/
template<typename T>
inline bool Stackll<T>::isEmpty()
{
	return m_stack.isEmpty();
}