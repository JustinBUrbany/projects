#include <ostream>
using std::ostream;
/*************************************************************
* Author:		Justin.Urbany
* Filename:		Exception.h
* Date Created:	1/23/17
* Modifications:	1/24/17-added comments
**************************************************************/
#ifndef EXCEPTION_H
#define EXCEPTION_H
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
*		Create a copy of an exceptin
*	operator = (const Exception & copy)
*		set one Exception equal to the other Exception
*	~Exception()
*		clear memory for the Exception
*
* Methods:
*	const char * getMessage() returns the current message in the exception
*	void setMessage(char * msg) set the current message in the exception
*************************************************************************/
class Exception
{
	friend ostream & operator<<(ostream & stream, const Exception & except);
public:
	Exception();
	Exception(char * msg);
	Exception(const Exception & copy);
	~Exception();
	Exception & operator=(const Exception & rhs);
	const char * getMessage();
	void setMessage(char * msg);

private:
	char * m_msg;
};

#endif