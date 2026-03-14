class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n

        count = 0
        for i in range(n):
            for j in range(n):
                if nums[j] < nums[i]:
                    count += 1
            ans[i] = count
            count = 0
        
        return ans