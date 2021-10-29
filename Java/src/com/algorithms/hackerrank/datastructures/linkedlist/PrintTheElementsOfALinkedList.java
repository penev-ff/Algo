/*
  Problem Statement:
  [Print the Elements of a Linked List](https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/)
 */

package com.algorithms.hackerrank.datastructures.linkedlist;

/**
 * @author Ivan Penev
 */
public class PrintTheElementsOfALinkedList {

    // Reference
    class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;
    }


    static void printLinkedList(SinglyLinkedListNode head) {

        while (head != null) {
            System.out.println(head.data);
            head = head.next;
        }

    }

}
