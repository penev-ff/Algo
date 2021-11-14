/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
        {
            return head; // nullptr
        }

        /* Recursive approach
        int k = n;
        return removeNthFromEndRec(head, k);
        */

        /* Iterative approach (two-pointers) */

        ListNode *fast = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        ListNode *slow = head;
        ListNode *prev = nullptr;
        while (fast)
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        if (slow == head)
        {
            head = head->next;
            delete slow;
        }
        else
        {
            prev->next = slow->next;
            delete slow;
        }

        return head;
    }

    // Recursive approach
    ListNode *removeNthFromEndRec(ListNode *head, int &k)
    {
        if (!head)
        {
            --k;
            return head; // nullptr
        }

        head->next = removeNthFromEndRec(head->next, k);

        if (k-- == 0)
        {
            ListNode *next = head->next;
            delete head;
            return next;
        }

        return head;
    }
};
