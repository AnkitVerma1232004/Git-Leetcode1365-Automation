#include <iostream>
#include <vector>
#include <ctime>
#include "../solutions/Solution.cpp"

using namespace std;

static bool any_failed = false;

void testCase(const vector<int>& nums, const vector<int>& expected) {
    clock_t start = clock();
    vector<int> out = Solution().smallerNumbersThanCurrent(const_cast<vector<int>&>(nums));
    clock_t end = clock();

    if (out == expected) {
        cout << "PASS (" << (end - start) << "ms)\n";
    } else {
        cout << "FAIL (" << (end - start) << "ms)\n";
        cout << "  Input:    ";
        for (int v : nums) cout << v << " ";
        cout << "\n";
        cout << "  Expected: ";
        for (int v : expected) cout << v << " ";
        cout << "\n  Got:      ";
        for (int v : out)   cout << v << " ";
        cout << "\n";
        any_failed = true;
    }
}

int main() {
    testCase({8,1,2,2,3},     {4,0,1,1,3});
    testCase({1,2,2,3,4},     {0,1,1,3,4});
    testCase({6,5,4,8},       {2,1,0,3});
    testCase({7,7,7,7},       {0,0,0,0});
    testCase({1},             {0});
    testCase({3,2,1},         {2,1,0});
    testCase({9,7,5,6,8},     {4,2,0,1,3});
    testCase({5,4,3,2,1},     {4,3,2,1,0});
    testCase({10,10,10,10},   {0,0,0,0});
    testCase({0,2,4,6,8,10},  {0,1,2,3,4,5});
    testCase({-1,-2,-3,-4},   {3,2,1,0});
    return any_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
