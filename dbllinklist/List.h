//#include "Exception.h"
#ifndef LIST_H
#define LIST_H

template<typename T>
class Node;

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
	void Extract(T data);
	void InsertAfter(T lookfordata, T nndata);
	void InsertBefore(T lookfordata, T nndata);
	Node<T> * getHead() const;
	Node<T> * getTail() const;
	void PrintForwards();
	void PrintBackwards();

private:
	Node<T> * m_Head;
	Node<T> * m_Tail;
};


template<typename T>
inline List<T>::List() : m_Head(nullptr), m_Tail(nullptr)
{
}

template<typename T>
inline List<T>::List(const List & copy) 
{

	*this = copy;
}

template<typename T>
inline List<T>::~List()
{
	Purge();
}

template<typename T>
inline List<T> & List<T>::operator=(const List<T> & rhs)
{
	if (this != &rhs) //if left hand side is not the same as the rhs
	{
		m_Head = nullptr; // Set Head to nullptr
		m_Tail = nullptr; // Set Tail to nullptr
		if (rhs.m_Head)
		{
			m_Head = rhs.m_Head; //make left head the same as right head
			m_Tail = rhs.m_Tail; //make left tail the same as right tail
		}
		
	}

	return *this;
}

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

template<typename T>
inline const T & List<T>::First()
{
	if (!isEmpty())  //if the list isn't empty
		return m_Head->m_Data; //return the data at the head node
	else
		throw Exception("No Data in First list is empty"); //otherwise throw an exception

}

template<typename T>
inline const T & List<T>::Last()
{
	if (!isEmpty())
		return m_Tail->m_Data; //if list isn't empty return data at tail
	else
		throw Exception("No Data in Last list is empty"); //otherwise throw exception that list was empty
}

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

template<typename T>
inline void List<T>::Extract(T data)
{
	if (!isEmpty())
	{
		Node<T> * travel = m_Head; //make a new node travel
		while (travel != nullptr && travel->m_Data != data) //if the travel isn't null ptr and travels data isn't the same as the passed in data
		{
			travel = travel->m_Next; //go to the next node
		}
		if (travel != nullptr) //if the data is found in the list
		{
			if (travel->m_Data == m_Head->m_Data) //check if the data was at the head
			{
				travel->m_Next->m_Previous = nullptr; //if the data was the head set the second nodes previous to nullptr
				m_Head = travel->m_Next; //make the second node the head
			}
			else if (travel->m_Data == m_Tail->m_Data)
			{
				travel->m_Previous->m_Next = nullptr;
				m_Tail = travel->m_Previous;
			}
			else
			{
				travel->m_Next->m_Previous = travel->m_Previous;
				travel->m_Previous->m_Next = travel->m_Next;
			}
			delete travel;

		}
		else
		{
			throw Exception("The data you were looking for wasn't in the list");
		}

	}
	else
	{
		throw Exception("The List was empty");
	}
	
}

template<typename T>
inline void List<T>::InsertAfter(T lookfordata, T nndata)
{
	Node<T> * NN = new Node<T>(nndata);
	Node<T> * temp = new Node<T>(lookfordata);
	Node<T> * travel = m_Head;
	if (travel != nullptr)
	{
		while (travel != nullptr && temp->m_Data != travel->m_Data)
		{
			travel = travel->m_Next;
		}
		if (travel != nullptr)
		{
			if (temp->m_Data == m_Head->m_Data)
			{
				m_Head->m_Next->m_Previous = NN;
				NN->m_Next = m_Head->m_Next;
				NN->m_Previous = m_Head;
				m_Head->m_Next = NN;
			}
			else if (temp->m_Data == m_Tail->m_Data)
			{
				m_Tail->m_Next = NN;
				NN->m_Previous = m_Tail;
				NN->m_Next = nullptr;
				m_Tail = NN;
			}
			else
			{
				travel->m_Next->m_Previous = NN;
				NN->m_Next = travel->m_Next;
				travel->m_Next = NN;
				NN->m_Previous = travel;
			}
		}
		else
		{
			throw Exception("Can't insertafter because data you were looking for wasn't in List");
		}
	}
	else
	{
		throw Exception("List is empty can insert After anything in Empty List");
	}
	delete temp;
}

template<typename T>
inline void List<T>::InsertBefore(T lookfordata, T nndata)
{
	Node<T> * NN = new Node<T>(nndata);
	Node<T> * temp = new Node<T>(lookfordata);
	Node<T> * travel = m_Head;
	if (travel != nullptr)
	{
		while (travel != nullptr && temp->m_Data != travel->m_Data)
		{
			travel = travel->m_Next;
		}
		if (travel != nullptr)
		{
			if (temp->m_Data == m_Head->m_Data)
			{
				NN->m_Previous = nullptr;
				NN->m_Next = m_Head;
				m_Head->m_Previous = NN;
				m_Head = NN;
			}
			else if (temp->m_Data == m_Tail->m_Data)
			{
				m_Tail->m_Previous->m_Next = NN;
				NN->m_Previous = m_Tail->m_Previous;
				m_Tail->m_Previous = NN;
				NN->m_Next = m_Tail;
			}
			else
			{
				travel->m_Previous->m_Next = NN;
				NN->m_Previous = travel->m_Previous;
				NN->m_Next = travel;
				travel->m_Previous = NN;
			}
		}
		else
		{
			throw Exception("The data you were looking for wasn't in the list!");
		}
	}
	else
	{
		throw Exception("Your list is Empty!");
	}
	delete temp;
}

template<typename T>
inline Node<T> * List<T>::getHead() const
{
	return m_Head;
}

template<typename T>
inline Node<T> * List<T>::getTail() const
{
	return m_Tail;
}

template<typename T>
inline void List<T>::PrintForwards()
{
	Node<T> * travel = m_Head;
	while (travel != nullptr)
	{
		cout << travel->m_Data << ' ';
		travel = travel->m_Next;
	}
}

template<typename T>
inline void List<T>::PrintBackwards()
{
	Node<T> * travel = m_Tail;
	while (travel != nullptr)
	{
		cout << travel->m_Data << ' ';
		travel = travel->m_Previous;
	}
}

#endif LIST_H

