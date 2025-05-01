Leetcode Question no 1365
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/

# 1365. How Many Numbers Are Smaller Than the Current Number

## Problem Statement

Given the array `nums`, for each `nums[i]` find out how many numbers in the array are smaller than it.  
That is, for each `nums[i]`, count the number of indices `j` such that `j != i` and `nums[j] < nums[i]`.

Return the answer in an array.

---

## Constraints

- `2 <= nums.length <= 500`
- `0 <= nums[i] <= 100`

---

## Examples

### Example 1

**Input:**
```
nums = [8, 1, 2, 2, 3]
```

**Output:**
```
[4, 0, 1, 1, 3]
```

**Explanation:**
- nums[0] = 8 → smaller numbers: [1, 2, 2, 3] → 4 numbers
- nums[1] = 1 → smaller numbers: [] → 0 numbers
- nums[2] = 2 → smaller numbers: [1] → 1 number
- nums[3] = 2 → smaller numbers: [1] → 1 number
- nums[4] = 3 → smaller numbers: [1, 2, 2] → 3 numbers

---

### Example 2

**Input:**
```
nums = [6, 5, 4, 8]
```

**Output:**
```
[2, 1, 0, 3]
```

---

### Example 3

**Input:**
```
nums = [7, 7, 7, 7]
```

**Output:**
```
[0, 0, 0, 0]
```

---

## Task

Implement a function that takes an array `nums` and returns an array where each element at index `i` represents how many numbers in the array are smaller than `nums[i]`.

---
