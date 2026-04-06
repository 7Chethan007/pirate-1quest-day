# Last updated: 4/6/2026, 8:53:32 AM
'''
2 pointer approach 
Missed this part
```
- > If nums[left] + nums[right] < k: The sum is too small. To increase it, move the left pointer to the right.

--> If nums[left] + nums[right] > k: The sum is too large. To decrease it, move the right pointer to the left.
```
'''

1class Solution:
2    def maxOperations(self, nums: List[int], k: int) -> int:
3        # Step 1: Sort the array
4        nums.sort()
5        
6        left = 0
7        right = len(nums) - 1
8        operations = 0
9        
10        # Step 2: Move pointers toward each other
11        while left < right:
12            current_sum = nums[left] + nums[right]
13            
14            if current_sum == k:
15                operations += 1
16                left += 1
17                right -= 1
18            elif current_sum < k:
19                # Sum is too small, need a larger value
20                left += 1
21            else:
22                # Sum is too large, need a smaller value
23                right -= 1
24                
25        return operations