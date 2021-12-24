/*
  Problem Statement:
  [Cycle Detection](https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/)
 */
package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
public class CycleDetection {
    // Reference
    private static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;
    }

    static boolean hasCycle(SinglyLinkedListNode head) {
        if (head == null) return false;

        SinglyLinkedListNode slow = head,
                fast = head;

        while (fast != null) {
            fast = fast.next;
            if (fast == slow) return true;

            if (fast == null) return false;
            fast = fast.next;

            if (fast == slow) return true;

            slow = slow.next;
        }

        return false;
    }
}
