package tests;

import solutions.Solution;
import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // Basic test cases
        testCase(sol, new int[]{8, 1, 2, 2, 3}, new int[]{4, 0, 1, 1, 3});
        testCase(sol, new int[]{6, 5, 4, 8}, new int[]{2, 1, 0, 3});
        testCase(sol, new int[]{7, 7, 7, 7}, new int[]{0, 0, 0, 0});
        testCase(sol, new int[]{1}, new int[]{0});
        testCase(sol, new int[]{3, 2, 1}, new int[]{2, 1, 0});
        testCase(sol, new int[]{1, 2, 3, 4}, new int[]{0, 1, 2, 3});
        testCase(sol, new int[]{0, 2, 4, 6, 8}, new int[]{0, 1, 2, 3, 4});
        testCase(sol, new int[]{5, 10, 15, 5, 10}, new int[]{0, 2, 4, 0, 2});

        // Edge test cases
        testCase(sol, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE, 0, -1, 1}, new int[]{4, 0, 2, 1, 3});
        testCase(sol, new int[]{10, 10, 10, 10, 10}, new int[]{0, 0, 0, 0, 0});
        testCase(sol, new int[]{100, 99, 98, 97, 96}, new int[]{4, 3, 2, 1, 0});
        testCase(sol, new int[]{Integer.MAX_VALUE, Integer.MAX_VALUE - 1}, new int[]{1, 0});
        testCase(sol, new int[]{0, 1, 2, 3, 4, 5, -1}, new int[]{1, 2, 3, 4, 5, 6, 0});
        testCase(sol, new int[]{5, 10, 15, 5, 10, 15}, new int[]{0, 2, 4, 0, 2, 4});
        testCase(sol, new int[]{1000, -1000, 500, -500, 0}, new int[]{4, 0, 3, 1, 2});
        testCase(sol, new int[]{0, -1, -2, -3, -4, -5}, new int[]{5, 4, 3, 2, 1, 0});
        testCase(sol, new int[]{1, 2, 2, 3, 3, 3}, new int[]{0, 1, 1, 3, 3, 3});
    }

    public static void testCase(Solution sol, int[] nums, int[] expected) {
        long startTime = System.currentTimeMillis();
        int[] output = sol.smallerNumbersThanCurrent(nums);
        long endTime = System.currentTimeMillis();

        if (Arrays.equals(output, expected)) {
            System.out.println("Test case passed in " + (endTime - startTime) + "ms");
        } else {
            System.out.println("Test case failed in " + (endTime - startTime) + "ms");
            System.out.println("Expected: " + Arrays.toString(expected));
            System.out.println("Got: " + Arrays.toString(output));
        }
    }
}
