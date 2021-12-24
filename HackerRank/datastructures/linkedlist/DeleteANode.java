/*
  Problem Statement:
  [Delete a Node](https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem)
 */
package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
public class DeleteANode {
    // Reference
    private static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;
    }

    public static SinglyLinkedListNode deleteNode(SinglyLinkedListNode llist, int position) {
        if (llist == null) return null;

        if (position == 0) {
            llist = llist.next;
            return llist;
        }

        SinglyLinkedListNode prev = llist;
        while (prev.next != null && position != 1) {
            prev = prev.next;
            --position;
        }

        if (position == 1 && prev.next != null) {
            prev.next = prev.next.next;
        }

        return llist;
    }
}
