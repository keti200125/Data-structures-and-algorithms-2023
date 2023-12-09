#include<iostream>
#include<list>
#include "linked-list-utils.h"

/*
template<class T>
void insertSorted(std::list<T>& ll, const T& elem)
{
    auto it=ll.begin();
    
    while(it=ll.end())
    {
        while(it*<elem)
        {
            ++it;
        }
    }
}
*/

template<class T>
LinkedListNode<T>* insertSorted(LinkedListNode<T>* ll, const T& elem)
{
    LinkedListNode<T>* newElem=new LinkedListNode<T>(elem);
    LinkedListNode<T>* it=ll,*next;
    if(!ll)
        return newElem;

    if(it->data>elem)
    {
        newElem->next=it;
        return newElem;
    }

    while(it->next && it->next->data <elem)
    {
        it=it->next;
    }
    next=it->next;
    newElem->next=next;
    it->next=newElem;
    return ll;
}




int main()
{
    LinkedListNode<int> *ll = new LinkedListNode(1,
     new LinkedListNode(2,
     new LinkedListNode(4,
     new LinkedListNode(5))));

    printList(ll);
    insertSorted(ll,3);
    printList(ll);
    freeList(ll);

}