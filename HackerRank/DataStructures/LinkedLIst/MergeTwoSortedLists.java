/*
  Problem Statement:
  [Merge two sorted linked lists](https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/)
 */
package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 * Time Complexity: O(max(N,M))
 * Space Complexity: O(N + M)
 */
public class MergeTwoSortedLists {
    // Reference
    private static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        public SinglyLinkedListNode(int data) {
            this.data = data;
        }
    }

    static SinglyLinkedListNode mergeLists(SinglyLinkedListNode head1, SinglyLinkedListNode head2) {
        if (head1 == null) return head2;
        if (head2 == null) return head1;

        int headVal;
        if (head1.data < head2.data) {
            headVal = head1.data;
            head1 = head1.next;
        } else {
            headVal = head2.data;
            head2 = head2.next;
        }

        SinglyLinkedListNode head = new SinglyLinkedListNode(headVal);
        SinglyLinkedListNode runner = head;

        while (head1 != null && head2 != null) {
            if (head1.data < head2.data) {
                runner.next = new SinglyLinkedListNode(head1.data);
                head1 = head1.next;
            } else {
                runner.next = new SinglyLinkedListNode(head2.data);
                head2 = head2.next;
            }

            runner = runner.next;
        }

        while (head1 != null) {
            runner.next = new SinglyLinkedListNode(head1.data);
            head1 = head1.next;
            runner = runner.next;
        }

        while (head2 != null) {
            runner.next = new SinglyLinkedListNode(head2.data);
            head2 = head2.next;
            runner = runner.next;
        }

        return head;
    }

}
