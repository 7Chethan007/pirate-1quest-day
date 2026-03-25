// Last updated: 3/25/2026, 9:08:00 AM
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();


        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = n - 1;
            while (l < r) {
                int threeSum = nums[i] + nums[l] + nums[r];
                
                if (threeSum > 0) {
                    --r;
                } 
                else if (threeSum < 0) {
                    ++l;
                } 
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;

                    // Skip duplicates for the second element
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    // Skip duplicates for the third element
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
            }
        }
        return res;
    }
};
