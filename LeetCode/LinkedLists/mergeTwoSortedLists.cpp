#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1 || !list2)
        return (!list1) ? list2 : list1;

    ListNode *merged;
    ListNode *start;
    ListNode *it1 = list1;
    ListNode *it2 = list2;
    if (it1->val <= it2->val)
    {
        merged = it1;
        start = it1;
        it1 = it1->next;
    }
    else
    {
        merged = it2;
        start = it2;
        it2 = it2->next;
    }
    
    while (it1 && it2)
    {
        if (it1->val <= it2->val)
        {
            merged->next = it1;
            it1 = it1->next;
        }
        else
        {
            merged->next = it2;
            it2 = it2->next;
        }
        merged = merged->next;
    }
    while (it1)
    {
        merged->next = it1;
        merged = merged->next;
        it1 = it1->next;
    }
    while (it2)
    {
        merged->next = it2;
        merged = merged->next;
        it2 = it2->next;
    }
    return start;
}