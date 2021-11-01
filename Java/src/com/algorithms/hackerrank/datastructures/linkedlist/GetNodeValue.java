/*
  Problem Statement:
  [Get Node Value](https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/)
 */
package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
public class GetNodeValue {
    // Reference
    private static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;
    }

    public static int getNode(SinglyLinkedListNode llist, int positionFromTail) {
        if (llist == null) return 0;

        SinglyLinkedListNode slow = llist;
        SinglyLinkedListNode runner = llist.next;

        while (runner != null && positionFromTail > 0) {
            runner = runner.next;
            --positionFromTail;
        }

        while (runner != null) {
            runner = runner.next;
            slow = slow.next;
        }

        return slow.data;
    }


}
