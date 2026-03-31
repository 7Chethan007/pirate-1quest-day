# Last updated: 3/31/2026, 8:53:46 AM
'''
In place swap &&
Tortoise & hare algorithm
'''

1from typing import List
2
3class Solution:
4    def moveZeroes(self, nums: List[int]) -> None:
5        """
6        Do not return anything, modify nums in-place instead.
7        """
8        n = len(nums)
9        slow = 0  # Points to the next position to place a non-zero element
10        
11        for fast in range(n):
12            # If the current element is non-zero
13            if nums[fast] != 0:
14                # Swap the elements at 'slow' and 'fast'
15                nums[slow], nums[fast] = nums[fast], nums[slow]
16                # Move the 'slow' pointer forward
17                slow += 1