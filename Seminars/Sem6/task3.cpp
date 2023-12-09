#include<iostream>
#include "linked-list-utils.h"
#include<list>

template<class T>
bool cycle(const std::list<T>& ll)
{
    if(ll.empty())
        return false;
    //std::list<T>::iterator slow=ll.begin();
    auto slow=ll.begin();
    auto fast=ll.begin();

    while(true)
    {
        ++slow;
        ++fast;
        if(fast==ll.end())
            return false;
        ++fast;
        if(fast==ll.end)
            return false;
        
        if(fast==slow)
            return true;
    }
}

template<class T>
bool linkedListCycle(LinkedListNode<T>* ll)
{
    LinkedListNode<T>* slow = ll;
    LinkedListNode<T>* fast = ll;

    while(fast && fast->next && slow)
    {
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow)
            return true;
    }
    return false;
}

int main()
{
    /**
    using Node =LinkedListNode<int>;

    Node* last =new Node(6);

    Node* ll= new Node(1,
    new Node(2,
    new Node(3,
    new Node(4,
    new Node(5,  
    last)))));

    last->next=ll->next->next;

    std::cout<<linkedListCycle(ll);
    */

}