// Last updated: 3/25/2026, 9:02:21 AM
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return n;  // every element has at least 0 greater elements

        sort(nums.begin(), nums.end());

        int count = 0;
        int i = 0;

        while (i < n) {
            int j = i;
            // find the end of the block of equal values
            while (j + 1 < n && nums[j + 1] == nums[i]) {
                j++;
            }

            // number of strictly greater elements = all elements after this block
            int greater = n - 1 - j;

            if (greater >= k) {
                // all elements in this block are qualified
                count += (j - i + 1);
            }

            i = j + 1; // move to next distinct value
        }

        return count;
    }
};
