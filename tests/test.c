#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


// Function to test the solution with different test cases
void testCase(int* nums, int n, int* expected) {
    clock_t start = clock();
    int returnSize;
    int* output = smallerNumbersThanCurrent(nums, n, &returnSize);
    clock_t end = clock();

    int passed = (returnSize == n);
    for (int i = 0; i < n && passed; i++) {
        if (output[i] != expected[i]) {
            passed = 0;
        }
    }

    if (passed) {
        printf("✅ Passed in %ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    } else {
        printf("❌ Failed in %ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
        printf("Expected: ");
        for (int i = 0; i < n; i++) printf("%d ", expected[i]);
        printf("\nGot     : ");
        for (int i = 0; i < n; i++) printf("%d ", output[i]);
        printf("\n");
    }

    free(output);
}

int main() {
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

    return 0;
}
