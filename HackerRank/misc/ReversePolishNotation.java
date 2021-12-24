/*
 Author: Ivan Penev
 Source: https://www.hackerrank.com/contests/hacksouthcarolinaint/challenges/reverse-polish-notation/
 Time Complexity: O(Q*N), Q := Queries, N := Operations in each query
 Space Complexity: O(N)
 */

package com.algorithms.hackerrank.misc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ReversePolishNotation {

    private static void Solve(String problem) {

        List<Integer> stack = new ArrayList<>();
        String[] tokens = problem.split(" ");

        for (String token : tokens) {
            try {

                int val = Integer.parseInt(token);
                stack.add(val);

            } catch (NumberFormatException nfe) {

                if (stack.isEmpty()) {
                    System.out.println("NO");
                    return;
                }

                int res = 0;

                if (token.equals("y")) {
                    int val = stack.remove(stack.size() - 1);
                    res = 2 * val + 1;

                } else if (token.equals("z")) {

                    if (stack.size() < 3) {
                        System.out.println("NO");
                        return;
                    }

                    int a = stack.remove(stack.size() - 1);
                    int b = stack.remove(stack.size() - 1);
                    int c = stack.remove(stack.size() - 1);

                    res = c + 2 * b + 3 * a;

                } else {

                    if (stack.size() < 2 || !isValidOp(token)) {
                        System.out.println("NO");
                        return;
                    }

                    int rhs = stack.remove(stack.size() - 1);
                    int lhs = stack.remove(stack.size() - 1);

                    switch (token) {
                        case "+" -> res = lhs + rhs;
                        case "-" -> res = lhs - rhs;
                        case "*" -> res = lhs * rhs;
                        case "/" -> {
                            if (rhs == 0) {
                                System.out.println("NO");
                                return;
                            }
                            res = lhs / rhs;
                        }
                        case "x" -> res = lhs * lhs + rhs;
                    }
                }

                stack.add(res);
            }
        }

        if (stack.size() != 1) {
            System.out.println("NO");
            return;
        }

        System.out.println(stack.get(0));
    }

    private static boolean isValidOp(String token) {
        return switch (token) {
            case "+", "-", "*", "/", "x" -> true;
            default -> false;
        };
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int queries = in.nextInt();
        in.nextLine();

        for (int q = 0; q < queries; q++) {
            String problem = in.nextLine();
            Solve(problem);
        }

    }
}
