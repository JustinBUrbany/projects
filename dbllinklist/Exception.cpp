#include "Exception.h"

Exception::Exception() :m_msg(nullptr)
{
}

Exception::Exception(char * msg) : m_msg(nullptr)
{
	if (msg != nullptr)
	{
		m_msg = new char[strlen(msg)];
		strcpy(m_msg, msg);
	}
}

Exception::Exception(const Exception & copy)
{
	*this = copy;
}

Exception::~Exception()
{
	delete[]m_msg;
}

Exception & Exception::operator=(const Exception & rhs)
{
	if (this != &rhs)
	{
		delete[]m_msg;
		m_msg = nullptr;
		if (rhs.m_msg != nullptr)
		{
			m_msg = new char[strlen(rhs.m_msg)];
			strcpy(m_msg, rhs.m_msg);
		}
	}
	return *this;
}

const char * Exception::getMessage()
{
	return m_msg;
}

void Exception::setMessage(char * msg)
{
	delete[]m_msg;
	m_msg = new char[strlen(msg)];
	strcpy(m_msg, msg);
}


ostream & operator<<(ostream & stream, const Exception & except)
{
	stream << except.m_msg;
	return stream;
}