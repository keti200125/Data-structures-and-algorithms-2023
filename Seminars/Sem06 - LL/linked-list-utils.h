#include <iostream>

template <class T>
struct LinkedListNode
{
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(const T &elem, LinkedListNode<T> *n = nullptr) : data{elem}, next{n} {}
};

template <class T>
void freeList(LinkedListNode<T> *ll)
{
    while (ll)
    {
        LinkedListNode<T> *toDelete = ll;
        ll = ll->next;
        delete toDelete;
    }
}

template<class T>
void printList(const LinkedListNode<T>* ll)
{
    const LinkedListNode<T>* it=ll;

    while(it)
    {
        std::cout<<it->data<<" ";
        it=it->next;
    }
    std::cout<<std::endl;
}