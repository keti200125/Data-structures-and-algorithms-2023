#include<iostream>
#include "linked-list-utils.h"

template<class T>
void reverse(LinkedListNode<T>*& ll)
{
    LinkedListNode<T> *next=nullptr, *prev=nullptr, *it=ll;
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
LinkedListNode<T>* findOneBeforeMiddle(LinkedListNode<T>* ll)
{
    LinkedListNode<T>* slow=ll,* fast=ll,*it=ll;
    while(fast && fast->next)
    {
        it=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast)
        return slow;
    return it;
}

template<class T>
void shuffle(LinkedListNode<T>*& ll)
{
    if(!ll && !ll->next)
        return ll;

    LinkedListNode<T>* head=ll;
    LinkedListNode<T>* end=findOneBeforeMiddle(ll);
    LinkedListNode<T>* mid=end->next;
    reverse(mid);
    end->next=nullptr;
    end=mid;
    while(end->next)
    {
        end=end->next;
    }
    end->next=head;
    ll=mid;
}



int main()
{
    LinkedListNode<int>* ll=new LinkedListNode(1,
    new LinkedListNode(2, 
    new LinkedListNode(3,
    new LinkedListNode(4,
    new LinkedListNode(5)))));

    printList(ll);
    shuffle(ll);
    printList(ll);
    freeList(ll);

}