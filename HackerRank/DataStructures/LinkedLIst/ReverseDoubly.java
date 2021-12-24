/*
  Problem Statement:
  [Reverse a doubly linked list](https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/)
 */
package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
public class ReverseDoubly {
    // Reference
    private static class DoublyLinkedListNode {
        int data;
        DoublyLinkedListNode next;
        DoublyLinkedListNode prev;

        public DoublyLinkedListNode(int data) {
            this.data = data;
        }
    }

    public static DoublyLinkedListNode reverse(DoublyLinkedListNode llist) {
        if (llist == null || llist.next == null) return llist;

        DoublyLinkedListNode prev = null, curr = llist;

        while (curr != null) {
            prev = curr.prev;
            curr.prev = curr.next;
            curr.next = prev;

            curr = curr.prev;
        }

        return prev.prev;
    }


}
