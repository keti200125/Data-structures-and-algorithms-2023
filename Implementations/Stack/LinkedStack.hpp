#pragma once

template<class T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& elem, Node<T>* n = nullptr) : data{ elem }, next{ n } {}
};

template<class T>
class LinkedStack
{
private:

	Node<T>* head;
	size_t size;

	void  copy(const LinkedStack<T>& other);
	void free();
public:
	void push(const T& data);
	void pop();
	const T& top() const;
	bool empty() const;
	size_t getSize() const;

	LinkedStack();
	LinkedStack(const LinkedStack<T>& other);
	LinkedStack<T>& operator=(const LinkedStack<T>& other);
	~LinkedStack();
};

template<class T>
inline void LinkedStack<T>::copy(const LinkedStack<T>& other)
{
	free();

	LinkedStack<T>* otherHead = other.head;
	LinkedStack<T> helper;
	while (!otherHead.empty)
	{
		helper.push(otherHead->head);
		otherHead = otherHead->next;
	}

	while (!helper.empty())
	{
		push(helper.top());
		helper.pop();
	}

}

template<class T>
inline void LinkedStack<T>::free()
{
	while (!empty())
	{
		pop();
	}

}

template<class T>
inline void LinkedStack<T>::push(const T& data)
{
	size++;
	LinkedStack<T>* newNode = new Node<T>(data, head);
	head = newNode;

}


template<class T>
inline void LinkedStack<T>::pop()
{
	if (empty())
	{
		throw "Empty stack"
	}

	Node<T>* temp = head;
	head = head->next;
	delete temp;

	size--;
}

template<class T>
inline const T& LinkedStack<T>::top() const
{
	if (empty())
	{
		throw "Empty Stack"
	}
	return head->data;
}


template<class T>
inline bool LinkedStack<T>::empty() const
{
	return size == 0;
}

template<class T>
inline size_t LinkedStack<T>::getSize() const
{
	return size;
}


template<class T>
inline LinkedStack<T>::LinkedStack() : head{ nullptr }, size{ 0 } {}

template<class T>
inline LinkedStack<T>::LinkedStack(const LinkedStack<T>& other)
{
	copy(other);
}

template<class T>
inline LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template<class T>
inline LinkedStack<T>::~LinkedStack()
{
	free();
}
