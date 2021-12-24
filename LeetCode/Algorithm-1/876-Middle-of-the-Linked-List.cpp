/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/middle-of-the-linked-list/
 *  Time: O(n) (actually it's n/2)
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

class Solution
{
public:
    static ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};
