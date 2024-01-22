#include <iostream>
#include "linked-list-utils.h"

//think

void partition(LinkedListNode<int> *&head, int x)
{
    LinkedListNode<int> *it = head, *small = nullptr, *big = nullptr, *smallIt, *bigIt;
    while (it)
    {
        if (it->data < x)
        {
            if (!small)
            {
                small = it;
                it = it->next; 
                small->next = nullptr;
                smallIt = small;
            }
            else
            {
                smallIt->next = it;
                it = it->next;
                smallIt = smallIt->next;
                smallIt->next = nullptr;
            }
            continue;
        }
        if (it->data >= x)
        {
            if (!big)
            {
                big = it;
                it = it->next;
                big->next = nullptr;
                bigIt = big;
            }
            else
            {
                bigIt->next = it;
                it = it->next;
                bigIt = bigIt->next;
                bigIt->next = nullptr;
            }
            continue;
        }
    }
    smallIt->next = big;
    head = small;
}

// if we want x in the middle
void partitionMid(LinkedListNode<int> *&head, int x)
{
    LinkedListNode<int> *it = head, *small = nullptr, *smallIt = nullptr, *big = nullptr,
                        *bigIt = nullptr, *mid = nullptr, *midEnd = nullptr;

    while (it)
    {
        if (it->data < x)
        {
            if (!small)
            {
                small = it;
                it = it->next; // 2
                small->next = nullptr;
                smallIt = small;
            }
            else
            {
                smallIt->next = it;
                it = it->next;
                smallIt = smallIt->next;
                smallIt->next = nullptr;
            }
            continue;
        }
        if (it->data > x)
        {
            if (!big)
            {
                big = it;
                it = it->next;
                big->next = nullptr;
                bigIt = big;
            }
            else
            {
                bigIt->next = it;
                it = it->next;
                bigIt = bigIt->next;
                bigIt->next = nullptr;
            }
            continue;
        }

        if (it->data == x)
        {
            if (!mid)
            {
                mid = it;
                it = it->next;
                mid->next = nullptr;
                midEnd = mid;
            }
            else
            {
                midEnd->next = it;
                it = it->next;
                midEnd = midEnd->next;
            }
            continue;
        }
    }

    smallIt->next = mid;
    midEnd->next = big;

    head = small;
}

int main()
{
    LinkedListNode<int> *ll = new LinkedListNode(1,
                                                 new LinkedListNode(4,
                                                                    new LinkedListNode(3,
                                                                                       new LinkedListNode(2,
                                                                                                          new LinkedListNode(5, new LinkedListNode(2))))));

    printList(ll);
    partition(ll, 3);
    printList(ll);
    freeList(ll);
}