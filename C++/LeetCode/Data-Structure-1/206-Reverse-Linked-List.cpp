/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/reverse-linked-list/
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
    ListNode *reverseList(ListNode *head)
    {
        if (head)
        {
            ListNode *prev = nullptr;
            ListNode *next = head->next;

            while (next)
            {
                head->next = prev;
                prev = head;
                head = next;

                next = next->next;
            }

            head->next = prev;
        }

        return head;
    }
};
