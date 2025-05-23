import time
import sys
import os

# Add the parent directory to the Python path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from solutions.Solution import Solution

failed = False  # Flag to track if any test failed

def test_case(nums, expected):
    global failed
    start = time.time()
    out = Solution().smallerNumbersThanCurrent(nums)
    elapsed = (time.time() - start) * 1000
    if out == expected:
        print(f"PASS ({elapsed:.2f}ms)")
    else:
        print(f"FAIL ({elapsed:.2f}ms)")
        print("  Input:   ", nums)
        print("  Expected:", expected)
        print("  Got:     ", out)
        failed = True

if __name__ == "__main__":
    test_case([8,1,2,2,3],     [4,0,1,1,3])
    test_case([6,5,4,8],       [2,1,0,3])
    test_case([7,7,7,7],       [0,0,0,0])
    test_case([1],             [0])
    test_case([3,2,1],         [2,1,0])
    test_case([1,2,2,3,4],     [0,1,1,3,4])
    test_case([9,7,5,6,8],     [4,2,0,1,3])
    test_case([5,4,3,2,1],     [4,3,2,1,0])
    test_case([10,10,10,10],   [0,0,0,0])
    test_case([0,2,4,6,8,10],  [0,1,2,3,4,5])
    test_case([-1,-2,-3,-4],   [3,2,1,0])

    if failed:
        sys.exit(1)
