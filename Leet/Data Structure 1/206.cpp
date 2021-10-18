/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/reverse-linked-list/
 *  Time: O(n)
 *  Space: O(1)
 * 
 *  Given the head of a singly linked list,
 *  reverse the list, and return the reversed list. 
 * 
 *  Examples:
 * 
 *  Input: head = [1,2,3,4,5]
 *  Output: [5,4,3,2,1]
 * 
 *  Input: head = [1,2]
 *  Output: [2,1]
 * 
 *  Input: head = []
 *  Output: []
 * 
 *  Constraints:
 *
 *  The number of nodes in the list is the range [0, 5000].
 *  -5000 <= Node.val <= 5000
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
