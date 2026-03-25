# Last updated: 3/25/2026, 9:03:11 AM
class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * (2 * n)
        for i in range(n):
            ans[i] = ans[i + n] = nums[i]
        
        return ans