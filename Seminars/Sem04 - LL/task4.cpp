#include <iostream>
#include "linked-list-utils.h"

template <class T>
LinkedListNode<T> *findOneBeforeMiddle(LinkedListNode<T> *ll)
{
    LinkedListNode<T> *slow = ll;
    LinkedListNode<T> *fast = ll;
    LinkedListNode<T> *prevSlow;

    while (fast && fast->next)
    {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return prevSlow;
}

template <class T>
void reverse(LinkedListNode<T> *&ll)
{
    LinkedListNode<T> *it = ll;
    LinkedListNode<T> *next = nullptr;
    LinkedListNode<T> *prev = nullptr;

    while (it)
    {
        next = it->next;
        it->next = prev;
        prev = it;
        it = next;
    }
    ll = prev;
}

template <class T>
void reorder(LinkedListNode<T> *ll)
{
    if (!ll || !ll->next)
        return;

    LinkedListNode<T> *firstStart = ll;
    LinkedListNode<T> *firstEnd = findOneBeforeMiddle(ll);
    LinkedListNode<T> *secondStart = firstEnd->next;
    firstEnd->next = nullptr;
    reverse(secondStart);

    LinkedListNode<T> *it = ll;
    firstStart = firstStart->next;
    while (firstStart)
    {
        it->next = secondStart;
        it = it->next;

        secondStart = secondStart->next;

        it->next = firstStart;
        it = it->next;

        firstStart = firstStart->next;
    }

    it->next = secondStart;
}

void reorderWithTwoPointers(LinkedListNode<int> *ll)
{
    if (!ll || !ll->next)
        return;

    // LinkedListNode<int>* mid = findMiddle(ll);
    LinkedListNode<int> *mid = findOneBeforeMiddle(ll)->next;
    reverse(mid);

    LinkedListNode<int> *firstHalf = ll;
    LinkedListNode<int> *currentPair = nullptr;
    LinkedListNode<int> *backOfList = nullptr;

    while (mid)
    {
        currentPair = firstHalf;
        firstHalf = firstHalf->next;

        // Случая в който имаме нечетен брой елементи
        if (!firstHalf)
        {
            backOfList->next = currentPair;
            backOfList = backOfList->next;
            break;
        }

        currentPair->next = mid;
        mid = mid->next;

        if (backOfList)
            backOfList->next = currentPair; // Пренасочи края към коректната двойка. Ако е nullptr нямаме какво да пренасочваме.

        backOfList = currentPair->next; // И един бърз ъпдейт на края - вече края на коректния лист е стария лист + новата двойка
    }

    backOfList->next = nullptr;
}

int main()
{
    LinkedListNode<int> *ll = new LinkedListNode(1,
                                                 new LinkedListNode(2,
                                                                    new LinkedListNode(3,
                                                                                       new LinkedListNode(4,
                                                                                                          new LinkedListNode(5)))));

    printList(ll);
    reorder(ll);
    printList(ll);
    freeList(ll);
}