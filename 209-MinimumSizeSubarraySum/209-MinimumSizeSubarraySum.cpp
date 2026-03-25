// Last updated: 3/25/2026, 9:06:03 AM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int l = 0, curSum = 0;
        int n = nums.size();

        for(int r = 0; r < n; r++) {
            curSum += nums[r];
            while(curSum >= target) {
                if(r-l+1 < minLen) minLen = r-l+1;

                curSum -= nums[l];
                l++;
            }
        }
        return ((minLen != INT_MAX) ? minLen : 0);
    }
};