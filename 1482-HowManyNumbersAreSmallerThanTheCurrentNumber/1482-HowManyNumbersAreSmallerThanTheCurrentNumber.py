# Last updated: 3/25/2026, 9:03:53 AM
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
        #  n =[8,1,2,2,3]
        bucket = [0] * 102
        
        for num in nums:
            bucket[num] += 1
        # b = [0,1,2,1,0,0,0,0,1]
        
        # Step 2: prefix sum (how many numbers ≤ i)
        for i in range(1, 102):
            bucket[i] += bucket[i - 1]
        # b = [0,1,3,4,4,4,4,4,5]
        
        # Step 3: build result
        res = [0] * len(nums)
        # r = [0,0,0,0,0] 
        
        for i in range(len(nums)):
            if nums[i] != 0:
                res[i] = bucket[nums[i] - 1]
                        # b[n[i] - 1]
                        # b[8-1] = 7 ---> We need it to be strictly less than 'i'
                        # So this step if you forget later once debug u'll get it it's easy
        
        return res