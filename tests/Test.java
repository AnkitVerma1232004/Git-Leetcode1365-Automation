package tests;

import solutions.Solution;
import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        boolean allPassed = true;

        allPassed &= testCase(sol, new int[]{8,1,2,2,3}, new int[]{4,0,1,1,3});
        allPassed &= testCase(sol, new int[]{6,5,4,8},   new int[]{2,1,0,3});
        allPassed &= testCase(sol, new int[]{7,7,7,7},   new int[]{0,0,0,0});
        allPassed &= testCase(sol, new int[]{1},         new int[]{0});
        allPassed &= testCase(sol, new int[]{3,2,1},     new int[]{2,1,0});
        allPassed &= testCase(sol, new int[]{1,2,2,3,4}, new int[]{0,1,1,3,4});
        allPassed &= testCase(sol, new int[]{9,7,5,6,8}, new int[]{4,2,0,1,3});
        allPassed &= testCase(sol, new int[]{5,4,3,2,1}, new int[]{4,3,2,1,0});
        allPassed &= testCase(sol, new int[]{10,10,10,10}, new int[]{0,0,0,0});
        allPassed &= testCase(sol, new int[]{0,2,4,6,8,10}, new int[]{0,1,2,3,4,5});
        allPassed &= testCase(sol, new int[]{-1,-2,-3,-4}, new int[]{3,2,1,0});

        if (!allPassed) {
            System.exit(1);
        }
    }

    private static boolean testCase(Solution sol, int[] nums, int[] expected) {
        long start = System.currentTimeMillis();
        int[] out = sol.smallerNumbersThanCurrent(nums);
        long end = System.currentTimeMillis();

        boolean pass = Arrays.equals(out, expected);
        if (pass) {
            System.out.println("PASS (" + (end - start) + "ms)");
        } else {
            System.out.println("FAIL (" + (end - start) + "ms)");
            System.out.println("  Input:    " + Arrays.toString(nums));
            System.out.println("  Expected: " + Arrays.toString(expected));
            System.out.println("  Got:      " + Arrays.toString(out));
        }
        return pass;
    }
}
