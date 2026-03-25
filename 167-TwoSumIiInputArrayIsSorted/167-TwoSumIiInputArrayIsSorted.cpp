// Last updated: 3/25/2026, 9:06:26 AM
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0;
        int right = numbers.size()-1;

        while(right > left) {
            int sum = numbers[left] + numbers[right];
            if(sum > target) right--;
            else if (sum < target) left++;
            else{
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
        }

        return res;
    }
};