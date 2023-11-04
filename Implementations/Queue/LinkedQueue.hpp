
#pragma once

template<class T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& elem, Node<T>* n = nullptr) : data{ d }, next{ n } {}
};

template<class T>
class LinkedQueue
{
private:
	Node<T>* head;
	Node<T>* tail;
	size_t size;

	void free();
	void copy(const LinkedQueue<T>& other);

public:

	LinkedQueue();
	LinkedQueue(const LinkedQueue<T>& other);
	LinkedQueue<T>& operator=(const LinkedQueue<T>& other);
	~LinkedQueue();

	bool empty() const;
	void push(const T& elemData);
	void pop();
	const T& front() const;
	T& front();
	size_t size() const;

};

template<class T>
inline void LinkedQueue<T>::free()
{
	while (!empty())
	{
		pop();
	}
}

template<class T>
inline void LinkedQueue<T>::copy(const LinkedQueue<T>& other)
{
	free();
	if (other.empty())
	{
		head = tail = nullptr;
	}

	LinkedQueue<T>* otherHead = other.head;
	while (!otherHead.empty())
	{
		push(otherHead->data);
		otherHead = otherHead->next;
	}

}

template<class T>
inline LinkedQueue<T>::LinkedQueue() :size{ 0 } {}

template<class T>
inline LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other)
{
	copy(other);
}

template<class T>
inline LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

template<class T>
inline LinkedQueue<T>::~LinkedQueue()
{
	free();
}

// O(1)
template<class T>
inline bool LinkedQueue<T>::empty() const
{
	return size == 0;
}

// O(1)
template<class T>
inline void LinkedQueue<T>::push(const T& elemData)
{
	Node<T>* newElem = new Node<T>(elemData, nullptr);
	if (empty())
	{
		head = tail = newElem;
	}
	else
	{
		tail->next = newElem;
		tail = tail->next;
	}
}

// O(1)
template<class T>
inline void LinkedQueue<T>::pop()
{
	if (empty())
	{
		throw "No elements"
	}
	else if (size == 1)
	{
		tail = head = nullptr;
	}
	else
	{
		Node* todelete = head;
		head = head->next;
		delete todelete;
	}
}

// O(1)
template<class T>
inline const T& LinkedQueue<T>::front() const
{
	if (empty())
	{
		throw "No elements"
	}

	return head->data;
}

// O(1)
template<class T>
inline T& LinkedQueue<T>::front()
{
	if (empty())
	{
		throw "No elements"
	}

	return head->data;
}

// O(1)
template<class T>
inline size_t LinkedQueue<T>::size() const
{
	return size;
}
