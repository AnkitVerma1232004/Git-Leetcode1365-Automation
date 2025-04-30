#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    // Allocate result array
    int* res = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Create sorted copy
    int* sorted = malloc(numsSize * sizeof(int));
    memcpy(sorted, nums, numsSize * sizeof(int));
    qsort(sorted, numsSize, sizeof(int), cmp);
    
    // Map number to count of smaller numbers
    int* countMap = calloc(101, sizeof(int)); // Assuming nums[i] in [0, 100] per problem constraints
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && sorted[i] != sorted[i-1]) {
            countMap[sorted[i]] = count;
        }
        count++;
    }
    
    // Map original numbers to counts
    for (int i = 0; i < numsSize; i++) {
        res[i] = countMap[nums[i]];
    }
    
    free(sorted);
    free(countMap);
    return res;
}
