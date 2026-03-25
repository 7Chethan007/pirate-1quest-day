# Last updated: 3/25/2026, 9:05:13 AM
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max = count = 0
        n = len(nums)

        for i in range(n):
            if(nums[i] == 1): 
                count += 1
            else:
                count = 0

            if count > max:
                max = count

        return max