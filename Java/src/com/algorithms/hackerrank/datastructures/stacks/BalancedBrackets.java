/*
  Problem Statement:
  [Balanced Brackets](https://www.hackerrank.com/challenges/balanced-brackets/)
 */
package com.algorithms.hackerrank.datastructures.stacks;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * @author Ivan Penev
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
public class BalancedBrackets {

    public static String isBalanced(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        char[] brackets = s.toCharArray();

        boolean isBalanced = true;
        for (char bracket : brackets) {
            if (isOpening(bracket)) {
                stack.add(bracket);
            } else if (stack.isEmpty()) {
                isBalanced = false;
                break;
            } else {
                char tos = stack.getLast();

                if (getClosingEquivalent(tos) != bracket) {
                    isBalanced = false;
                    break;
                }

                stack.removeLast();
            }
        }

        return isBalanced && stack.isEmpty() ? "YES" : "NO";
    }

    private static char getClosingEquivalent(char openingBracket) {
        return switch (openingBracket) {
            case '(' -> ')';
            case '{' -> '}';
            case '[' -> ']';
            default -> '?';
        };
    }

    private static boolean isOpening(char bracket) {
        return bracket == '(' || bracket == '{' || bracket == '[';
    }
}
