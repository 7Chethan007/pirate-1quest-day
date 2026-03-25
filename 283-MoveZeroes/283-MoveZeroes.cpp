// Last updated: 3/25/2026, 9:05:40 AM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int insertPos = 0;  // where the next non-zero should go

        // 1. Move all non-zeros to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }

        // 2. Fill the rest with zeros
        while (insertPos < n) {
            nums[insertPos] = 0;
            insertPos++;
        }
    }
};
