# Last updated: 4/7/2026, 8:53:06 AM
# iterate using the second example
1class Solution:
2    def longestOnes(self, nums: list[int], k: int) -> int:
3        left = 0
4        max_length = 0
5        zero_count = 0
6        
7        for right in range(len(nums)):
8            # If we encounter a 0, increment our zero counter
9            if nums[right] == 0:
10                zero_count += 1
11            
12            # If zeros exceed k, shrink the window from the left
13            while zero_count > k:
14                if nums[left] == 0:
15                    zero_count -= 1
16                left += 1
17            
18            # Update the maximum length found so far
19            # Window size is (right - left + 1)
20            max_length = max(max_length, right - left + 1)
21            
22        return max_length