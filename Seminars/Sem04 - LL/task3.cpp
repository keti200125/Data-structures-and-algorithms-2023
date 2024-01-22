#include <iostream>
#include "linked-list-utils.h"

template <class T>
const T &middleLL(LinkedListNode<T> *ll)
{
    if (!ll)
        throw "Empty list";

    LinkedListNode<T> *it = ll;
    LinkedListNode<T> *itFast = ll;

    while (itFast && itFast->next)
    {
        it = it->next;
        itFast = itFast->next->next;
    }

    return it->data;
}

int main()
{
    LinkedListNode<int> *ll = new LinkedListNode(1,
                                                 new LinkedListNode(2,
                                                                    new LinkedListNode(3,
                                                                                       new LinkedListNode(4,
                                                                                                          new LinkedListNode(5)))));

    std::cout << middleLL(ll);

    freeList(ll);
}