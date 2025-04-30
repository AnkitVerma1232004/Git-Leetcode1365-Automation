class Solution:
    def smallerNumbersThanCurrent(self, nums):
        sorted_nums = sorted(nums)
        count_map = {}
        count = 0
        for i, num in enumerate(sorted_nums):
            if i == 0 or sorted_nums[i] != sorted_nums[i-1]:
                count_map[num] = count
            count += 1
        return [count_map[num] for num in nums]
