// Last updated: 3/25/2026, 9:06:24 AM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        long long l = 0, n = nums.size(), h = n -1;

        while(l < h) {
            int m = l + (h - l) / 2;

            if(nums[m] > nums[m+1]) h = m;
            else l = m + 1;
        }
        return l;
    }
};