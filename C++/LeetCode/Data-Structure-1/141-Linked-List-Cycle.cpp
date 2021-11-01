/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/linked-list-cycle/
 *  Time: O(n)
 *  Space: O(1)
 * 
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;

        ListNode *slow = head,
                 *fast = head;

        while (fast)
        {
            fast = fast->next;
            if (fast == slow)
                return true;

            if (!fast)
                return false;
            fast = fast->next;

            if (fast == slow)
                return true;

            slow = slow->next;
        }

        return false;
    }
};