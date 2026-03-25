// Last updated: 3/25/2026, 9:03:48 AM
class Solution {
    public int[] shuffle(int[] nums, int n) {
        int ans[] = new int[nums.length];
        for(int i = 0; i < nums.length ; i+=2) {
            ans[i] = nums[i/2];
            ans[i+1] = nums[nums.length-n];
            n -= 1;
        }
        return ans;
    }
}