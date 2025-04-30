package solutions;

import java.util.Arrays;
import java.util.HashMap;

public class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        
        HashMap<Integer, Integer> countMap = new HashMap<>();
        int count = 0;
        for (int i = 0; i < sorted.length; i++) {
            if (i == 0 || sorted[i] != sorted[i-1]) {
                countMap.put(sorted[i], count);
            }
            count++;
        }
        
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            res[i] = countMap.get(nums[i]);
        }
        return res;
    }
}
