// Last updated: 3/25/2026, 9:05:05 AM
// C++
#include <vector>
using namespace std;

class Solution {
public:
        int singleNonDuplicate(vector<int>& nums) {
                int n = nums.size();
                if (n == 1) return nums[0];
                if (nums[0] != nums[1]) return nums[0];
                if (nums[n-1] != nums[n-2]) return nums[n-1];

                int low = 1, high = n - 2;
                while (low <= high) {
                        int mid = low + (high - low) / 2;
                        if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

                        bool goRight = (mid % 2 == 0 && nums[mid] == nums[mid+1]) ||
                                                   (mid % 2 == 1 && nums[mid] == nums[mid-1]);
                        if (goRight) low = mid + 1;
                        else high = mid - 1;
                }
                return -1;
        }
};


// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         // Base case only one element
//         if (n == 1)
//             return nums[0];
//         // Base case for 0th and nth index
//         if (nums[0] != nums[1])
//             return nums[0];
//         if (nums[n - 1] != nums[n - 2])
//             return nums[n - 1];

//         // low & high pointer after exclusing the first and last index's
//         int low = 1;
//         int high = n - 2;

//         // Binary Search
//         while (low <= high) {
//             int mid = (low + high) / 2;

//             // Check if middle element is the single element
//             if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
//                 return nums[mid];

//             // Check if we are in left or right half of the arr (even,odd) or
//             // (odd,even) In left side
//             if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || // left even
//                 (mid % 2 == 1 && nums[mid] == nums[mid - 1]))   // left odd
//             {
//                 low = mid + 1;
//             }
//             // In right side
//             // else { hight = mid - 1};
//             if ((mid % 2 == 0 && nums[mid] == nums[mid - 1]) || // left even
//                 (mid % 2 == 1 && nums[mid] == nums[mid + 1]))   // left odd
//             {
//                 high = mid - 1;
//             }
//         }
//         return -1;
//     }
// };