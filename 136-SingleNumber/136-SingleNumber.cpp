// Last updated: 3/25/2026, 9:06:40 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            res = res ^ nums[i];
        }
        return res;
    }
};