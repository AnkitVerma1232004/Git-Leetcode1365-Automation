#include <iostream>
#include <vector>
#include <ctime>
#include <climits>  // For INT_MAX and INT_MIN
//#include "Solution.h"
#include "../solutions/Solution.cpp" // Include the solution header file

using namespace std;

// Function to test the solution with different test cases
void testCase(Solution& sol, vector<int> nums, vector<int> expected) {
    clock_t startTime = clock(); // Start timing execution
    vector<int> output = sol.smallerNumbersThanCurrent(nums);
    clock_t endTime = clock(); // End timing execution

    // Compare output with expected result
    if (!expected.empty() && output == expected) {
        cout << "Test case passed in " << (endTime - startTime) << "ms" << endl;
    } else if (!expected.empty()) {
        cout << "Test case failed in " << (endTime - startTime) << "ms" << endl;
        cout << "Expected: ";
        for (int num : expected) cout << num << " ";
        cout << "\nGot: ";
        for (int num : output) cout << num << " ";
        cout << endl;
    } else {
        cout << "Test case executed in " << (endTime - startTime) << "ms" << endl;
    }
}

int main() {
    Solution sol;

    // Basic test cases
    testCase(sol, {8, 1, 2, 2, 3}, {4, 0, 1, 1, 3});
    testCase(sol, {6, 5, 4, 8}, {2, 1, 0, 3});
    testCase(sol, {7, 7, 7, 7}, {0, 0, 0, 0});
    testCase(sol, {1}, {0});
    testCase(sol, {3, 2, 1}, {2, 1, 0});
    testCase(sol, {1, 2, 3, 4}, {0, 1, 2, 3});
    testCase(sol, {0, 2, 4, 6, 8}, {0, 1, 2, 3, 4});
    testCase(sol, {5, 10, 15, 5, 10}, {0, 2, 4, 0, 2});
    testCase(sol, {100, 50, 25, 10, 75}, {4, 2, 1, 0, 3});
    //testCase(sol, {99, 100, 98, 100, 97}, {3, 4, 2, 4, 1});

    // Edge test cases
    testCase(sol, {INT_MAX, INT_MIN, 0, -1, 1}, {4, 0, 2, 1, 3});
    testCase(sol, {10, 10, 10, 10, 10}, {0, 0, 0, 0, 0});
    testCase(sol, {100, 99, 98, 97, 96}, {4, 3, 2, 1, 0});
    testCase(sol, {INT_MAX, INT_MAX - 1}, {1, 0});
    testCase(sol, {0, 1, 2, 3, 4, 5, -1}, {1, 2, 3, 4, 5, 6, 0});
    testCase(sol, {5, 10, 15, 5, 10, 15}, {0, 2, 4, 0, 2, 4});
    testCase(sol, {1000, -1000, 500, -500, 0}, {4, 0, 3, 1, 2});
    testCase(sol, {0, -1, -2, -3, -4, -5}, {5, 4, 3, 2, 1, 0});
    testCase(sol, {1, 2, 2, 3, 3, 3}, {0, 1, 1, 3, 3, 3});
    //testCase(sol, {1, 1000000000, -1000000000, 500, -500}, {2, 4, 0, 3, 1});

    return 0;
}
