import sys
import os
import time
#import random
from typing import List  # Import List for type hinting

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from solutions.Solution import Solution  # Ensure correct package structure

def test_case(sol: Solution, nums: List[int], expected: List[int]):
    """
    Function to test the solution with different test cases.
    """
    start_time = time.time()  # Start timing execution
    output = sol.smallerNumbersThanCurrent(nums)
    end_time = time.time()  # End timing execution
    
    # Compare output with expected result
    if expected and output == expected:
        print(f"Test case passed in {round((end_time - start_time) * 1000, 2)}ms")
    elif expected:
        print(f"Test case failed in {round((end_time - start_time) * 1000, 2)}ms")
        print(f"Expected: {expected}")
        print(f"Got: {output}")
    else:
        print(f"Test case executed in {round((end_time - start_time) * 1000, 2)}ms")

if __name__ == "__main__":
    sol = Solution()
    
    # Basic test cases
    test_case(sol, [8, 1, 2, 2, 3], [4, 0, 1, 1, 3])
    test_case(sol, [6, 5, 4, 8], [2, 1, 0, 3])
    test_case(sol, [7, 7, 7, 7], [0, 0, 0, 0])
    test_case(sol, [1], [0])
    test_case(sol, [3, 2, 1], [2, 1, 0])
    test_case(sol, [1, 2, 3, 4], [0, 1, 2, 3])
    test_case(sol, [0, 2, 4, 6, 8], [0, 1, 2, 3, 4])
    test_case(sol, [5, 10, 15, 5, 10], [0, 2, 4, 0, 2])
    #test_case(sol, [100, 50, 25, 10, 75], [4, 2, 1, 0, 3])
    
    # Edge test cases
    test_case(sol, [sys.maxsize, -sys.maxsize - 1, 0, -1, 1], [4, 0, 2, 1, 3])
    test_case(sol, [10, 10, 10, 10, 10], [0, 0, 0, 0, 0])
    test_case(sol, [100, 99, 98, 97, 96], [4, 3, 2, 1, 0])
    test_case(sol, [sys.maxsize, sys.maxsize - 1], [1, 0])
    test_case(sol, [0, 1, 2, 3, 4, 5, -1], [1, 2, 3, 4, 5, 6, 0])
    test_case(sol, [5, 10, 15, 5, 10, 15], [0, 2, 4, 0, 2, 4])
    test_case(sol, [1000, -1000, 500, -500, 0], [4, 0, 3, 1, 2])
    test_case(sol, [0, -1, -2, -3, -4, -5], [5, 4, 3, 2, 1, 0])
    test_case(sol, [1, 2, 2, 3, 3, 3], [0, 1, 1, 3, 3, 3])
    
    # large_case1 = [0] * 100000
    # test_case(sol, large_case1, [0] * 100000)
    
    # large_case2 = list(range(100000))
    # expected_large2 = list(range(100000))
    # test_case(sol, large_case2, expected_large2)
    
    # large_case3 = [random.randint(0, 1000000) for _ in range(100000)]
    # test_case(sol, large_case3, [])
