/*
  Problem Statement:
  [Compare two linked lists](https://www.hackerrank.com/challenges/compare-two-linked-lists/problem)
 */
package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 */
public class CompareTwoLinkedLists {
    // Reference
    private static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;
    }

    static boolean compareLists(SinglyLinkedListNode head1, SinglyLinkedListNode head2) {
        while (head1 != null && head2 != null) {
            if (head1.data != head2.data) {
                return false;
            }

            head1 = head1.next;
            head2 = head2.next;
        }

        // Both should be null or lengths are different
        return head1 == head2;
    }

}
