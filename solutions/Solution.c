/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//yo
#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int count = 1;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] < nums[i]) count++;
        }
        res[i] = count;
    }
    *returnSize = numsSize;
    return res;
}
