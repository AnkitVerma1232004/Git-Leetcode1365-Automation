#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int, int> countMap;
        int count = 0;
        for (int i = 0; i < sorted.size(); i++) {
            if (i == 0 || sorted[i] != sorted[i-1]) {
                countMap[sorted[i]] = count;
            }
            count++;
        }
        
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res[i] = countMap[nums[i]];
        }
        return res;
    }
};
