#include <iostream>
#include "linked-list-utils.h"

template <class T>
void reverseLL(LinkedListNode<T>*& ll)
{

    LinkedListNode<T> *it = ll;
    LinkedListNode<T> *reversed = nullptr;
    LinkedListNode<T> *lastElem = nullptr;
    while (it)
    {
        reversed = it;
        it = it->next;
        reversed->next = lastElem;
        lastElem = reversed;
    }
    ll = reversed;
}

template <class T>
void reverseLinkedList(LinkedListNode<T> *&ll)
{
    LinkedListNode<T> *previous = nullptr;
    LinkedListNode<T> *next = nullptr;
    LinkedListNode<T> *iterate = ll;
     // 1 2 3
    while (iterate)
    {
        next = iterate->next;
        iterate->next = previous;  
        previous = iterate;
        iterate = next; 
    }

    ll = previous;
}

int main()
{
    LinkedListNode<int> *ll = new LinkedListNode(1,
     new LinkedListNode(2,
     new LinkedListNode(3,
     new LinkedListNode(4, 
     new LinkedListNode(5)))));

    printList(ll);
    reverseLL(ll);
    printList(ll);

    freeList(ll);
}