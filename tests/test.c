#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Declare the function here — do NOT include Solution.c
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize);

static int any_failed = 0;

void testCase(int* nums, int n, int* expected) {
    clock_t start = clock();
    int returnSize;
    int* out = smallerNumbersThanCurrent(nums, n, &returnSize);
    clock_t end = clock();

    int passed = (returnSize == n);
    for (int i = 0; i < n && passed; i++) {
        if (out[i] != expected[i]) passed = 0;
    }

    if (passed) {
        printf("PASS (%ldms)\n", (end - start));
    } else {
        printf("FAIL (%ldms)\n", (end - start));
        printf("  Expected: ");
        for (int i = 0; i < n; i++) printf("%d ", expected[i]);
        printf("\n  Got:      ");
        for (int i = 0; i < n; i++) printf("%d ", out[i]);
        printf("\n");
        any_failed = 1;
    }
    free(out);
}

int main() {
    int t1[] = {8,1,2,2,3},  e1[] = {4,0,1,1,3};
    testCase(t1,5,e1);

    int t2[] = {6,5,4,8},    e2[] = {2,1,0,3};
    testCase(t2,4,e2);

    int t3[] = {7,7,7,7},    e3[] = {0,0,0,0};
    testCase(t3,4,e3);

    int t4[] = {1},          e4[] = {0};
    testCase(t4,1,e4);

    int t5[] = {3,2,1},      e5[] = {2,1,0};
    testCase(t5,3,e5);

    int t6[] = {1, 2, 2, 3, 4}, e6[] = {0, 1, 1, 2, 3};
    testCase(t6, 5, e6);

    int t7[] = {9, 7, 5, 6, 8}, e7[] = {4, 2, 0, 1, 3};
    testCase(t7, 5, e7);

    int t8[] = {5, 4, 3, 2, 1}, e8[] = {4, 3, 2, 1, 0};
    testCase(t8, 5, e8);

    int t9[] = {10, 10, 10, 10, 10}, e9[] = {0, 0, 0, 0, 0};
    testCase(t9, 5, e9);

    int t10[] = {1, 1, 1, 1}, e10[] = {0, 0, 0, 0};
    testCase(t10, 4, e10);

    int t11[] = {0, 2, 4, 6, 8, 10}, e11[] = {0, 1, 2, 3, 4, 5};
    testCase(t11, 6, e11);

    int t12[] = {3, 1, 4, 1, 5, 9}, e12[] = {2, 0, 3, 0, 4, 5};
    testCase(t12, 6, e12);

    int t13[] = {1, 3, 2, 4, 3, 1}, e13[] = {0, 3, 2, 4, 3, 0};
    testCase(t13, 6, e13);

    int t14[] = {9, 4, 7, 5, 6}, e14[] = {4, 0, 3, 1, 2};
    testCase(t14, 5, e14);

    return any_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
