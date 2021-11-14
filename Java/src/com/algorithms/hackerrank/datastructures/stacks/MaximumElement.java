/*
  Problem Statement:
  [Maximum Element](https://www.hackerrank.com/challenges/maximum-element/)
 */
package com.algorithms.hackerrank.datastructures.stacks;

import java.util.*;

/**
 * @author Ivan Penev
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
public class MaximumElement {
    /*
     * Complete the 'getMax' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts STRING_ARRAY operations as parameter.
     */
    public static List<Integer> getMax(List<String> operations) {
        List<Integer> result = new ArrayList<>();

        // Would be used as stack because Stack is a legacy collection
        Deque<Integer> elementsStack = new ArrayDeque<>();
        Deque<Integer> maximumsStack = new ArrayDeque<>();

        for (String operation : operations) {
            String[] tokens = operation.split(" ");

            int opCode = Integer.parseInt(tokens[0]);

            if (opCode == 1) {
                // Push
                int value = Integer.parseInt(tokens[1]);

                elementsStack.add(value);

                if (maximumsStack.isEmpty()) {
                    maximumsStack.add(value);
                } else {
                    int tos = maximumsStack.getLast();

                    maximumsStack.add(Math.max(tos, value));
                }

            } else if (opCode == 2) {
                // Delete
                if (!maximumsStack.isEmpty() && !elementsStack.isEmpty()) {
                    elementsStack.removeLast();
                    maximumsStack.removeLast();
                }

            } else if (opCode == 3) {
                // Print max
                if (!maximumsStack.isEmpty()) {
                    int tos = maximumsStack.getLast();

                    result.add(tos);
                }
            }
        }

        return result;
    }

}
