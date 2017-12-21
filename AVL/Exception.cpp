/*************************************************************
* Author:		Justin.Urbany
* Filename:		Exception.cpp
* Date Created:	1/23/17
* Modifications:	1/24/17-added comments
**************************************************************/
#include "Exception.h"
/**********************************************************************
* Purpose: Create an Exception intialize to nullptr
************************************************************************/
Exception::Exception() :m_msg(nullptr)
{
}
/**********************************************************************
* Purpose: Create an execption allocate space and set the msg to the
*	passed in message
************************************************************************/
Exception::Exception(char * msg) : m_msg(nullptr)
{
	if (msg != nullptr)
	{
		m_msg = new char[strlen(msg) + 1];
		strcpy(m_msg, msg);
	}
}
/**********************************************************************
* Purpose: Make a copy of an Exception
************************************************************************/
Exception::Exception(const Exception & copy)
{
	*this = copy;
}
/**********************************************************************
* Purpose: Clean up memory from an exception when goes out of scope
************************************************************************/
Exception::~Exception()
{
	delete[]m_msg;
	m_msg = nullptr;
}
/**********************************************************************
* Purpose: Assign one Exception to another Exception
************************************************************************/
Exception & Exception::operator=(const Exception & rhs)
{
	if (this != &rhs)
	{
		delete[]m_msg;
		m_msg = nullptr;
		if (rhs.m_msg != nullptr)
		{
			m_msg = new char[strlen(rhs.m_msg) + 1];
			strcpy(m_msg, rhs.m_msg);
		}
	}
	return *this;
}
/**********************************************************************
* Purpose: Get the message contained inside the Exception
* Precondition: Called from an Exception
* Postcondition: Return the curren message
************************************************************************/
const char * Exception::getMessage()
{
	return m_msg;
}
/**********************************************************************
* Purpose: Set the message to a new message
* Precondition: must pass in a message
* Postcondition: have the message set
************************************************************************/
void Exception::setMessage(char * msg)
{
	delete[]m_msg;
	if (msg != nullptr)
	{
		m_msg = new char[strlen(msg) + 1];
		strcpy(m_msg, msg);
	}
}
/**********************************************************************
* Purpose: Be able to display a excepion object
* Precondition: Take in an ostream object and an exception objext
* Postcondition: have put the exceptions message into the ostream object
************************************************************************/
ostream & operator<<(ostream & stream, const Exception & except)
{
	stream << except.m_msg;
	return stream;
}