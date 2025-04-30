#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    
    int* res = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    
    int* sorted = malloc(numsSize * sizeof(int));
    memcpy(sorted, nums, numsSize * sizeof(int));
    qsort(sorted, numsSize, sizeof(int), cmp);
    
   
    int* countMap = calloc(101, sizeof(int)); 
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && sorted[i] != sorted[i-1]) {
            countMap[sorted[i]] = count;
        }
        count++;
    }
    
  
    for (int i = 0; i < numsSize; i++) {
        res[i] = countMap[nums[i]];
    }
    
    free(sorted);
    free(countMap);
    return res;
}
