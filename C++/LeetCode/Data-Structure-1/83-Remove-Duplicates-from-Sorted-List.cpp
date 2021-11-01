/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/ 
 *  Time: O(n)
 *  Space: O(1)
 *  
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (head && head->next)
    {
        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr)
        {
            if (prev->val == curr->val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                curr = curr->next;
                prev = prev->next;
            }
        }
    }

    return head;
}