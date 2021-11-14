/*
  Problem Statement:
  [Inserting a Node Into a Sorted Doubly Linked List](https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem)
 */
package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
public class InsertionSortedDoubly {
    // Reference
    private static class DoublyLinkedListNode {
        int data;
        DoublyLinkedListNode next;
        DoublyLinkedListNode prev;

        public DoublyLinkedListNode(int data) {
            this.data = data;
        }
    }

    public static DoublyLinkedListNode sortedInsert(DoublyLinkedListNode head, int data) {
        DoublyLinkedListNode toInsert = new DoublyLinkedListNode(data);

        // Empty list
        if (head == null) return toInsert;

        DoublyLinkedListNode curr = head, prev = null;
        while (curr != null && curr.data < data) {
            prev = curr;
            curr = curr.next;
        }

        // End of list
        if (curr == null) {
            toInsert.prev = prev;
            prev.next = toInsert;
            return head;
        }

        toInsert.prev = prev;
        toInsert.next = curr;
        curr.prev = toInsert;

        if (prev != null)
            prev.next = toInsert;

        // The newly inserted element is inserted before the head
        if (curr == head)
            head = toInsert;

        return head;
    }


}
