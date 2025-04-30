#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    
    // Loop through each element
    for (int i = 0; i < numsSize; i++) {
        int count = 0;
        
        // Count how many numbers are smaller than nums[i]
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] < nums[i]) count++;
        }
        
        // Store the count in the result array
        res[i] = count;
    }

    *returnSize = numsSize;  // Set the return size
    return res;
}
