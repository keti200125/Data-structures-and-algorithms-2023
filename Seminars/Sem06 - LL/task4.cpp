#include<iostream>
#include<list>
#include "linked-list-utils.h"

template<class T>
LinkedListNode<T>* findfirstEnd(LinkedListNode<T>* ll)
{
    LinkedListNode<T> *slow=ll, *fast=ll,*firstEnd;

    while(slow && fast && fast->next)
    {
        firstEnd=slow;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return firstEnd;
}

template<class T>
void reverse(LinkedListNode<T>*& ll)
{
    LinkedListNode<T> *it=ll, *next=nullptr,*prev=nullptr;

    while(it)
    {
        next=it->next;
        it->next=prev;
        prev=it;
        it=next;
    }
    ll=prev;
}

template<class T>
bool isPalindrome(LinkedListNode<T>* ll)
{
    LinkedListNode<T> *firstEnd, *secondStart, *it=ll;
    if(!ll)
        throw "The list is empty";
    if(!ll->next)
        return true;
    
    firstEnd=findfirstEnd(it);
    secondStart=firstEnd->next;
    firstEnd->next=nullptr;
    reverse(secondStart);

    while(it)
    {
        if(it->data!=secondStart->data)
        {
            return false;
        }
        it=it->next;
        secondStart=secondStart->next;
    }
    return true;
}


int main()
{
    /*
    LinkedListNode<int> *ll = new LinkedListNode(1,
     new LinkedListNode(2,
     new LinkedListNode(3,
     new LinkedListNode(2,
     new LinkedListNode(1)))));

    */

    LinkedListNode<int> *ll = new LinkedListNode(1,
     new LinkedListNode(2,
     new LinkedListNode(3)));

    std::cout<<isPalindrome(ll);
    freeList(ll);

}