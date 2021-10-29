/*
  Problem Statement:
  [Insert a node at a specific position in a linked list](https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/)
 */

package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 */

public class InsertANodeAtASpecificPosition {
    // Reference
    private static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        public SinglyLinkedListNode(int data) {
            this.data = data;
        }
    }

    public static SinglyLinkedListNode insertNodeAtPosition(SinglyLinkedListNode head, int data, int position) {
        SinglyLinkedListNode curr = head;

        while (curr != null && position - 1 > 0) {
            curr = curr.next;
            --position;
        }

        if (position - 1 == 0) {
            if (curr == head || curr == null) {
                curr = new SinglyLinkedListNode(data);
                curr.next = head;
                head = curr;
            } else {
                SinglyLinkedListNode toInsert = new SinglyLinkedListNode(data);
                toInsert.next = curr.next;
                curr.next = toInsert;
            }
        }

        return head;
    }

}
