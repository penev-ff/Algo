/*
  Problem Statement:
  [Find Merge Point of Two Lists](https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/)
 */
package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 */
public class FindMergePoint {
    // Reference
    private static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;
    }

    // Another approach is to use fast & slow pointer
    static int findMergeNode(SinglyLinkedListNode head1, SinglyLinkedListNode head2) {
        if (head1 == null || head2 == null) return 0;

        int length1 = 0, length2 = 0;
        SinglyLinkedListNode curr1 = head1, curr2 = head2;

        while (curr1 != null) {
            curr1 = curr1.next;
            ++length1;
        }

        while (curr2 != null) {
            curr2 = curr2.next;
            ++length2;
        }

        curr1 = head1;
        curr2 = head2;

        int diff = Math.abs(length1 - length2);
        if (length1 > length2) {
            while (diff > 0) {
                curr1 = curr1.next;
                --diff;
            }
        } else {
            while (diff > 0) {
                curr2 = curr2.next;
                --diff;
            }
        }

        while (curr1 != curr2) {
            curr1 = curr1.next;
            curr2 = curr2.next;
        }

        return curr1.data;
    }
}
