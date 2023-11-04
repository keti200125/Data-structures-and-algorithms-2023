#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *it, *newHead;
    int num1, num2, result = 0, remainder = 0;
    bool firstElem = 1;

    while (l1 || l2)
    {
        num1 = (l1) ? l1->val : 0;
        num2 = (l2) ? l2->val : 0;
        result = num1 + num2 + remainder;
        remainder = result / 10;
        
        if (result > 9)
            result = result % 10;

        if (firstElem)
        {
            newHead = new ListNode(result);
            it = newHead;
            firstElem = 0;
        }
        else
        {
            it->next = new ListNode(result);
            it = it->next;
        }

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (remainder != 0)
        it->next = new ListNode(remainder);

    return newHead;
}