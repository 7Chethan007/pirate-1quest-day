// Last updated: 3/25/2026, 9:03:06 AM
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int> set;
        long long curSum = 0, maxSum = 0;
        int left = 0, right = 0;
        int n = nums.size();

        for(right = 0; right < n; right++) {
            while( set.count(nums[right]) || set.size() == k) {
                set.erase(nums[left]);
                curSum -= nums[left];
                left++;
            }
            curSum += nums[right];
            set.insert(nums[right]);
            if(set.size() == k) {
                maxSum = max(maxSum, curSum);
            }
        }
        return maxSum;
    }
};