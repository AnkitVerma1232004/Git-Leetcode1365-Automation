#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "../solutions/Solution.c"

// Function prototype
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize);

// Function to test the solution with different test cases
void testCase(int* nums, int n, int* expected) {
    clock_t startTime = clock(); // Start timing execution
    int returnSize;
    int* output = smallerNumbersThanCurrent(nums, n, &returnSize);
    clock_t endTime = clock(); // End timing execution
    
    // Compare output with expected result
    if (expected != NULL) {
        int passed = (returnSize == n);
        for (int i = 0; i < n && passed; i++) {
            if (output[i] != expected[i]) {
                passed = 0;
                break;
            }
        }
        if (passed) {
            printf("Test case passed in %ldms\n", (endTime - startTime));
        } else {
            printf("Test case failed in %ldms\n", (endTime - startTime));
            printf("Expected: ");
            for (int i = 0; i < n; i++) printf("%d ", expected[i]);
            printf("\nGot: ");
            for (int i = 0; i < n; i++) printf("%d ", output[i]);
            printf("\n");
        }
    } else {
        printf("Test case executed in %ldms\n", (endTime - startTime));
    }
    
    free(output);
}

int main() {
    // Basic test cases
    int test1[] = {8, 1, 2, 2, 3};
    int expected1[] = {4, 0, 1, 1, 3};
    testCase(test1, 5, expected1);
    
    int test2[] = {6, 5, 4, 8};
    int expected2[] = {2, 1, 0, 3};
    testCase(test2, 4, expected2);
    
    int test3[] = {7, 7, 7, 7};
    int expected3[] = {0, 0, 0, 0};
    testCase(test3, 4, expected3);
    
    int test4[] = {1};
    int expected4[] = {0};
    testCase(test4, 1, expected4);
    
    int test5[] = {3, 2, 1};
    int expected5[] = {2, 1, 0};
    testCase(test5, 3, expected5);
    
    // Edge test cases
    int test6[] = {INT_MAX, INT_MIN, 0, -1, 1};
    int expected6[] = {4, 0, 2, 1, 3};
    testCase(test6, 5, expected6);
    
    int test7[] = {10, 10, 10, 10, 10};
    int expected7[] = {0, 0, 0, 0, 0};
    testCase(test7, 5, expected7);
    
    int test8[] = {100, 99, 98, 97, 96};
    int expected8[] = {4, 3, 2, 1, 0};
    testCase(test8, 5, expected8);
    
    int test9[] = {INT_MAX, INT_MAX - 1};
    int expected9[] = {1, 0};
    testCase(test9, 2, expected9);
    
    // Large input cases
    // int* largeCase1 = (int*)calloc(100000, sizeof(int));
    // testCase(largeCase1, 100000, largeCase1);
    // free(largeCase1);
    
    // int* largeCase2 = (int*)malloc(100000 * sizeof(int));
    // int* expectedLarge2 = (int*)malloc(100000 * sizeof(int));
    // for (int i = 0; i < 100000; i++) {
    //     largeCase2[i] = i;
    //     expectedLarge2[i] = i;
    // }
    // testCase(largeCase2, 100000, expectedLarge2);
    // free(largeCase2);
    // free(expectedLarge2);
    
    // int* largeCase3 = (int*)malloc(100000 * sizeof(int));
    // srand(time(0));
    // for (int i = 0; i < 100000; i++) {
    //     largeCase3[i] = rand() % 1000000;
    // }
    // testCase(largeCase3, 100000, NULL);
    // free(largeCase3);
    
    return 0;
}
