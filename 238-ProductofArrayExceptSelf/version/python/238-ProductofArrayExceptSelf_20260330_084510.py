# Last updated: 3/30/2026, 8:45:10 AM
1class Solution:
2    def productExceptSelf(self, nums: list[int]) -> list[int]:
3        n = len(nums)
4        res = [1] * n
5        
6        # Step 1: Calculate Prefix products
7        # res[i] will contain the product of all elements to the left of i
8        prefix = 1
9        for i in range(n):
10            res[i] = prefix
11            prefix *= nums[i]
12            
13        # Step 2: Calculate Suffix products on the fly
14        # Multiply the existing prefix product by the product of elements to the right
15        suffix = 1
16        for i in range(n - 1, -1, -1):
17            res[i] *= suffix
18            suffix *= nums[i]
19            
20        return res