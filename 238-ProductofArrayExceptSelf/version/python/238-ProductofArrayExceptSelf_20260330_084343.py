# Last updated: 3/30/2026, 8:43:43 AM
1class Solution:
2    def productExceptSelf(self, nums: List[int]) -> List[int]:
3        # 1. Calculate the total product and count zeros
4        total_prod = 1
5        zero_count = nums.count(0)
6        
7        # If more than one zero exists, every result will be 0
8        if zero_count > 1:
9            return [0] * len(nums)
10        
11        for n in nums:
12            if n != 0:
13                total_prod *= n
14        
15        res = [0] * len(nums)
16        
17        # 2. Fill the result array
18        for i in range(len(nums)):
19            if zero_count == 1:
20                # If there's one zero, only the index with the zero gets a value
21                res[i] = total_prod if nums[i] == 0 else 0
22            else:
23                # Standard case: total product divided by current element
24                # Using // for integer division
25                res[i] = total_prod // nums[i]
26                
27        return res