/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/add-two-numbers/
 *  Time: O(max(m,n))
 *  Space: O(max(m,n))
 *  
*/

// Reference
// Definition for singly-linked list.
struct ListNode
{
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l1;
    if (!l2)
        return l2;

    ListNode dummyStackAttach;
    ListNode *curr = &dummyStackAttach;

    int sum, carry = 0;

    while (l1 || l2)
    {
        sum = 0;

        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;

        curr->next = new ListNode(sum % 10);
        carry = sum / 10;
        curr = curr->next;
    }

    if (carry)
        curr->next = new ListNode(carry);

    return dummyStackAttach.next;
}