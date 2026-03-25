// Last updated: 3/25/2026, 9:06:32 AM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // Binary search
        while (left < right) {
            int mid = left + (right - left) / 2;

            // If middle element is greater than the rightmost,
            // the min is in the right half.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // Min is in the left half (including mid)
                right = mid;
            }
        }

        // left == right -> index of minimum
        return nums[left];
    }
};
