#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == right || !head || !head->next)
        return head;

    ListNode *secondStart, *firstEnd = head, *secondEnd, *next = nullptr, *prev = nullptr;
    int l = left;

    if (left == 1)
    {
        firstEnd = nullptr;
        secondStart = head;
        if (right == 2)
        {
            firstEnd = secondStart->next;
            secondStart->next = firstEnd->next;
            firstEnd->next = secondStart;
            return firstEnd;
        }
    }
    else
    {
        while (l > 2)
        {
            firstEnd = firstEnd->next;
            l--;
        }
        secondStart = firstEnd->next;
    }
    right = right - left + 1;
    int r = right;
    while (right > 0 && secondStart)
    {
        next = secondStart->next;
        secondStart->next = prev;
        prev = secondStart;
        if (right == r)
            secondEnd = prev;
        secondStart = next;
        right--;
    }
    secondEnd->next = secondStart;
    if (firstEnd)
    {
        firstEnd->next = prev;
        return head;
    }
    return prev;
}
