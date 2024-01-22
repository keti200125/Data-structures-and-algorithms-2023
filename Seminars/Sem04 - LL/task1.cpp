#include <iostream>
#include "linked-list-utils.h"

template<class T>
void insertLL(LinkedListNode<T>*& ll, const T& elem)
{
    LinkedListNode<T>* toInsert=new LinkedListNode<T>(elem, ll);
    ll=toInsert;
}

int main()
{
    LinkedListNode<int>* ll;

    insertLL(ll,3);
    insertLL(ll,2);
    insertLL(ll,1);
    printList(ll);

    freeList(ll);
}