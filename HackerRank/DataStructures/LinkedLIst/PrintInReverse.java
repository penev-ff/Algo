/*
  Problem Statement:
  [Print in Reverse](https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/)
 */
package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
public class PrintInReverse {
    private static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        public SinglyLinkedListNode(int data) {
            this.data = data;
        }
    }

    public static void reversePrint(SinglyLinkedListNode llist) {
        if (llist == null)
            return;

        reversePrint(llist.next);
        System.out.println(llist.data);
    }
}
