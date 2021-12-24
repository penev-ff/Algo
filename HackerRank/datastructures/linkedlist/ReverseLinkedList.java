/*
  Problem Statement:
  [Reverse a linked list](https://www.hackerrank.com/challenges/reverse-a-linked-list/)
 */
package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
public class ReverseLinkedList {
    // Reference
    private static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;
    }

    public static SinglyLinkedListNode reverse(SinglyLinkedListNode llist) {
        SinglyLinkedListNode prev = null,
                curr = llist,
                next;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
}
