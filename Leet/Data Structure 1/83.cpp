/**
 *  Author: Ivan Penev
 *  Source: 
 *  Time: O(n)
 *  Space: O(1)
 *  
 * Given the head of a sorted linked list,
 * delete all duplicates such that each element
 * appears only once. 
 * Return the linked list sorted as well.
 * 
 *  Examples:
 * Input: head = [1,1,2]
 * Output: [1,2]
 * 
 * Input: head = [1,1,2,3,3]
 * Output: [1,2,3]
 * 
 *  Constraints:
 *
 *  The number of nodes in the list is in the range [0, 300].
 *  -100 <= Node.val <= 100
 *  The list is guaranteed to be sorted in ascending order.
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