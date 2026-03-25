// Last updated: 3/25/2026, 9:08:06 AM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        long long maxArea = 0;
        long long currArea = 0;
        while(left < right) {
            currArea = min(height[left],height[right]) * (right - left);
            maxArea = max(currArea, maxArea);

            if(height[left] < height[right]) left++;
            else right--;
        }

        return maxArea;
    }
};