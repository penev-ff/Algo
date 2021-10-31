/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/remove-linked-list-elements/
 *  Time: O(n)
 *  Space: O(1)
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

ListNode *removeElements(ListNode *head, int val)
{
    if (!head)
        return nullptr;

    while (head && head->val == val)
    {
        ListNode *toRemove = head;
        head = head->next;
        delete toRemove;
    }

    ListNode *runner = head;

    while (runner && runner->next)
    {
        if (runner->next->val == val)
        {
            ListNode *toRemove = runner->next;
            runner->next = toRemove->next;
            delete toRemove;
        }
        else
        {
            runner = runner->next;
        }
    }
}