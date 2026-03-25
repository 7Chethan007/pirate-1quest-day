// Last updated: 3/25/2026, 9:02:18 AM
class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> rightMostIndex; // value -> smallest index seen so far to the right
        int ans = INT_MAX;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            int rev = reverseNum(nums[i]);  // we need nums[j] == rev for some j > i

            if (rightMostIndex.count(rev)) {
                ans = min(ans, rightMostIndex[rev] - i);
            }

            // Store the smallest index to the right for nums[i]
            if (!rightMostIndex.count(nums[i])) {
                rightMostIndex[nums[i]] = i;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
