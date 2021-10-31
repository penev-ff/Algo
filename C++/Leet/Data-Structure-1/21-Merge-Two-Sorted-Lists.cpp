/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/merge-two-sorted-lists/
 *  Time: O(n + k)
 *  Space: O(n + k) - it's for the new merged list, but it could be solved without using extra memory
 * 
*/

// Definition for singly-linked list. (For reference)
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// A recursive approach is also possible if creating a new list is not necessary
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    ListNode *mergedHead;

    if (l1->val < l2->val)
    {
        mergedHead = new ListNode(l1->val);
        l1 = l1->next;
    }
    else
    {
        mergedHead = new ListNode(l2->val);
        l2 = l2->next;
    }

    ListNode *runner = mergedHead;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            runner->next = new ListNode(l1->val);
            l1 = l1->next;
        }
        else
        {
            runner->next = new ListNode(l2->val);
            l2 = l2->next;
        }
        runner = runner->next;
    }

    while (l1)
    {
        runner->next = new ListNode(l1->val);
        l1 = l1->next;
        runner = runner->next;
    }

    while (l2)
    {
        runner->next = new ListNode(l2->val);
        l2 = l2->next;
        runner = runner->next;
    }

    return mergedHead;
}