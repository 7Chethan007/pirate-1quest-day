// Last updated: 3/25/2026, 9:03:16 AM
class Solution {
    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int[] ans = new int[2*n];
        for(int i = 0 ; i < n ; i++) {
            int j = i;
            ans[i] = nums[i];
            ans[j+n] = nums[i];
        }
        

        return ans;
    }
}