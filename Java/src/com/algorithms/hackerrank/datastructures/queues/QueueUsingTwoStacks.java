/*
  Problem Statement:
  [Queue using Two Stacks](https://www.hackerrank.com/challenges/queue-using-two-stacks/)
 */
package com.algorithms.hackerrank.datastructures.queues;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Ivan Penev
 * Time Complexity: O(1) amortized
 * Space Complexity: O(2n)
 */
public class QueueUsingTwoStacks {
    private final List<Integer> pushStack = new ArrayList<>();
    private final List<Integer> popStack = new ArrayList<>();

    // Amortization
    private void transfer() {
        while (!pushStack.isEmpty()) {
            int pushStackTop = pushStack.remove(pushStack.size() - 1);
            popStack.add(pushStackTop);
        }
    }

    // O(1)
    public boolean isEmpty() {
        return pushStack.isEmpty() && popStack.isEmpty();
    }

    // O(1)
    public void enqueue(int val) {
        pushStack.add(val);
    }

    // O(1) amortized
    public void dequeue() {
        if (!isEmpty()) {
            if (popStack.isEmpty()) {
                transfer();
            }

            popStack.remove(popStack.size() - 1);
        }
    }

    // O(1) amortized
    public int front() {
        if (isEmpty()) {
            return -1; // Or throw underflow exception
        }

        if (popStack.isEmpty()) {
            transfer();
        }

        return popStack.get(popStack.size() - 1);
    }

    public static void main(String[] args) {
        // Reading the input
        Scanner in = new Scanner(System.in);

        final int ENQUEUE = 1, DEQUEUE = 2, FRONT = 3;

        QueueUsingTwoStacks queue = new QueueUsingTwoStacks();

        int queries = in.nextInt();

        for (int q = 0; q < queries; q++) {

            int opCode = in.nextInt();

            if (opCode == ENQUEUE) {
                // Enqueue
                int val = in.nextInt();
                queue.enqueue(val);

            } else if (opCode == DEQUEUE) {
                // Dequeue
                queue.dequeue();

            } else if (opCode == FRONT) {
                // Print Front
                System.out.println(queue.front());
            }

        }
    }
}

