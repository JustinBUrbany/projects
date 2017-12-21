#ifndef NODE_H
#define NODE_H

template<typename T>
class List;

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

template<typename T>
inline Node<T>::Node() :m_Next(nullptr), m_Previous(nullptr)
{
}

template<typename T>
inline Node<T>::Node(T Data) : m_Data(Data), m_Next(nullptr), m_Previous(nullptr)
{
}

template<typename T>
inline Node<T>::Node(const Node & copy)
{
	*this = copy;
}

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

template<typename T>
inline Node<T>::~Node()
{
	m_Next = nullptr;
	m_Previous = nullptr;
}

