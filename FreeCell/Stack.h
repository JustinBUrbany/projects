/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stack.h
* Date Created:	2/3/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#ifndef STACK_H
#define STACK_H
#include "Array.h"
/************************************************************************
* Class: Stack
*
* Purpose: Create a Stack of any type
*
* Manager functions:
* 	Stack (int size )
* 		Create a Stack with default size 13
*	Stack (const Stack & copy)
*		Create a copy of an Stack
*	operator = (const Stack & copy)
*		set one Stack to the another Stack
*	~Stack()
*		Delete the Stack and set array length back to zero
*
* Methods:
*	void Push(T Data)
*		Push data onto the stack at the current position
*	T & Pop;
*		Returns Data from the top of stack and removes that data
*	T & Peek
*		Returns the data from the top of stack and data remains at top of stack
*	int sizeofStack()
*			returns the current size of the stack
*	bool isEmpty()
*		returns if the stack is empty
*	bool isFull()
*		returns if stack is Full
*************************************************************************/
template<typename T>
class Stack
{
public:

	Stack(int size = 13);
	Stack(Stack & copy);
	Stack & operator=(Stack & rhs);
	~Stack();
	void Push(T Data);
	T & Pop();
	T & Peek();
	int SizeofStack();
	bool isEmpty();
	bool isFull();

private:
	int m_size;
	int m_position;
	Array<T> m_array;
};
#endif
/**********************************************************************
* Purpose: Set the Size of hte Stack Set the length of the contained
*		Array Object
*
* Precondtion: take in size if specified otherwise default 13
*
* Postcondition: None
*
************************************************************************/
template<typename T>
inline Stack<T>::Stack(int size) : m_size(size), m_position(-1)
{
	m_array.setLength(size);
}
/**********************************************************************
* Purpose: Copy one stack into another stack making them equal
*
* Precondtion: Take in  A stack object
*
* Postcondition: none
*
************************************************************************/
template<typename T>
inline Stack<T>::Stack(Stack & copy)
{
	*this = copy;
	return *this;
}
/**********************************************************************
* Purpose: Assign one stack to another stack making them equal
*
* Precondtion: Take in  A Stack
*
* Postcondition: Return A Stack equal to passed in Stack
*
************************************************************************/
template<typename T>
inline Stack<T> & Stack<T>::operator=(Stack & rhs)
{
	if (this != &rhs)
	{
		m_size = rhs.m_size;
		m_array = rhs.m_array;
		m_position = rhs.m_position;
	}
	return *this;
}
/**********************************************************************
* Purpose: Clean up memory used by the stack
*
* Precondtion: None
*
* Postcondition: None
*
************************************************************************/
template<typename T>
inline Stack<T>::~Stack()
{

}
/**********************************************************************
* Purpose: The purpose of this function is to add items onto the stack
*
* Precondtion: Take in Data if current size is less the max size add
*			the data to the top of the stack make the stack bigger
*
* Postcondition:
*
************************************************************************/
template<typename T>
inline void Stack<T>::Push(T Data)
{
	if ((m_position + 1) >= m_size)
		throw Exception("Overflow");
	m_array[m_position + 1] = Data;
	m_position++;
}
/**********************************************************************
* Purpose: To get the current data from the top of the stack and
*			Remove it from the top of the stack
*
* Precondtion: None
*
* Postcondition: If the current size greater then zero return what was
*			on top of stack and Remove it from the stack
*
************************************************************************/
template<typename T>
inline T & Stack<T>::Pop()
{
	if (m_position < 0)
		throw Exception("Underflow");
	m_position--;
	return m_array[m_position + 1];
}
/**********************************************************************
* Purpose: The purpose is to see what Data is on top of the stack
*			without removing it
*
* Precondtion: None
*
* Postcondition: If current size greater then zero return what was on
*				top of stack
*
************************************************************************/
template<typename T>
inline T & Stack<T>::Peek()
{
	if (m_position < 0)
		throw Exception("Nothing on Stack");
	return m_array[m_position];
}
/**********************************************************************
* Purpose: Get the size of the stack
*
* Precondtion: None
*
* Postcondition: Return the current size of the stack
*
************************************************************************/
template<typename T>
inline int Stack<T>::SizeofStack()
{
	return m_position + 1;
}
/**********************************************************************
* Purpose: To check and see if the stack is empty
*
* Precondtion: None
*
* Postcondition: Return true if the stack was empty
*
************************************************************************/
template<typename T>
inline bool Stack<T>::isEmpty()
{
	bool empty = false;
	if (m_position == -1)
	{
		empty = true;
	}
	return empty;
}
/**********************************************************************
* Purpose: Purpose is to check if the stack is full
*
* Precondtion: None
*
* Postcondition: Return true if the Stack is full
*
************************************************************************/
template<typename T>
inline bool Stack<T>::isFull()
{
	bool full = false;
	if (m_size == m_position + 1)
	{
		full = true;
	}
	return full;
}