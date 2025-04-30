#include <stdlib.h>
//
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    for (int i = 1; i < numsSize; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] < nums[i]) count++;
        }
        res[i] = count;
    }
    *returnSize = numsSize;
    return res;
}
