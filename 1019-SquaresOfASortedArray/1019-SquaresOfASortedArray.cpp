// Last updated: 3/25/2026, 9:04:28 AM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);          // pre-allocate!
        int l = 0, r = n - 1, pos = n - 1;

        while (l <= r) {
            int lsq = nums[l] * nums[l];
            int rsq = nums[r] * nums[r];
            if (lsq > rsq) {
                res[pos] = lsq;
                l++;
            } else {
                res[pos] = rsq;
                r--;
            }
            pos--;
        }
        return res;
    }
};
