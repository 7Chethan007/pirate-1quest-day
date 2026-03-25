// Last updated: 3/25/2026, 9:03:45 AM
class Solution {
    public int[] runningSum(int[] nums) {
        int n=nums.length;
        int idx=1;
        for(int i=1;i<n;i++){
            nums[idx++]=nums[i]+nums[i-1];
        }
        return nums;
    }
}