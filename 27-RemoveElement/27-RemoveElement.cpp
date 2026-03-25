// Last updated: 3/25/2026, 9:07:50 AM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;

        // Move through the array
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[left] = nums[i];  // overwrite unwanted vals
                left++;
            }
        }
        
        // left is now the count of valid elements
        return left;
    }
};



// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int n = nums.size();
//         int left = 0;
//         // First left find the first occurance of val
//         for(left = 0; left < n; left++) {
//             if(nums[left] == val) {
//                 break;
//             }
//         }

//         // Now that left point is the index that needs to be replaced 
//         // right = left+1 to n . What if left is pointing at the last index
//         if(left == (n-1)) {
//             return left+1;
//         }
//         else {
//             // find the first r value that is non key value that can be replaced
//             // then update nums[left] then update left to the index from where we took the value
//             int right = left+1;
//             for(int i = right; i < n; i++) {
//                 if(nums[i] != val) {
//                     nums[left] = nums[i];
//                     left = i;
//                     i++; 
//                 }
//             }
//             return (left-1);
//         }
        
//     }
// };