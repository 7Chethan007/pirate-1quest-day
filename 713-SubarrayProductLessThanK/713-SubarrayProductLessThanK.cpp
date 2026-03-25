// Last updated: 3/25/2026, 9:04:45 AM
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;   // no subarray product can be < k
        long long prod = 1;
        int left = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            // shrink window while product >= k
            while (prod >= k) {
                prod /= nums[left];
                left++;
            }
            // all subarrays ending at right with start >= left are valid
            count += (right - left + 1);
        }

        return count;
    }
};
