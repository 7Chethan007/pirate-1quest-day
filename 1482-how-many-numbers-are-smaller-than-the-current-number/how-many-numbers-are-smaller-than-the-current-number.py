class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        # n = len(nums)
        # ans = [0] * n

        # count = 0
        # for i in range(n):
        #     for j in range(n):
        #         if nums[j] < nums[i]:
        #             count += 1
        #     ans[i] = count
        #     count = 0
        
        # return ans
        # # T : O(n^2) && S : O(n)

        # Count Sort && HASH MAp
         # Step 1: frequency bucket
        bucket = [0] * 102
        
        for num in nums:
            bucket[num] += 1
        
        # Step 2: prefix sum (how many numbers ≤ i)
        for i in range(1, 102):
            bucket[i] += bucket[i - 1]
        
        # Step 3: build result
        res = [0] * len(nums)
        
        for i in range(len(nums)):
            if nums[i] != 0:
                res[i] = bucket[nums[i] - 1]
        
        return res