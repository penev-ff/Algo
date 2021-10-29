/*
  Problem Statement:
  [Insert a Node at the Tail of a Linked List](https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/)
 */

package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 */
public class InsertANodeAtTheTail {
    // Reference
    private static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        public SinglyLinkedListNode(int data) {
            this.data = data;
        }
    }

    static SinglyLinkedListNode insertNodeAtTail(SinglyLinkedListNode head, int data) {
        if (head != null) {
            SinglyLinkedListNode curr = head;

            while (curr.next != null) {
                curr = curr.next;
            }

            curr.next = new SinglyLinkedListNode(data);
        } else {
            head = new SinglyLinkedListNode(data);
        }

        return head;
    }

}
