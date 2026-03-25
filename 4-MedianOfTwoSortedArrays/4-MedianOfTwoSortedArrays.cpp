// Last updated: 3/25/2026, 9:08:14 AM
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure A is the smaller array
        vector<int> &A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        vector<int> &B = (nums1.size() <= nums2.size()) ? nums2 : nums1;

        int n = A.size();
        int m = B.size();
        int total = n + m;

        int left = 0;
        int right = n;                 // note: right = n, partition index runs [0..n]
        int half = (total + 1) / 2;    // number of elements in left partitions

        while (left <= right) {
            int i = left + (right - left) / 2; // partition in A: left has i elements
            int j = half - i;                  // partition in B: left has j elements

            int Aleft  = (i == 0) ? INT_MIN : A[i - 1];
            int Aright = (i == n) ? INT_MAX : A[i];
            int Bleft  = (j == 0) ? INT_MIN : B[j - 1];
            int Bright = (j == m) ? INT_MAX : B[j];

            // correct partition
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 1) {
                    // odd total -> max of lefts
                    return static_cast<double>( max(Aleft, Bleft) );
                } else {
                    // even total -> average of middle two
                    return ( (double)max(Aleft, Bleft) + (double)min(Aright, Bright) ) / 2.0;
                }
            }
            // too far right in A (Aleft > Bright) -> move left
            else if (Aleft > Bright) {
                right = i - 1;
            } else { // Aleft <= Bright but Bleft > Aright -> move right
                left = i + 1;
            }
        }

        // Should not reach here for valid input
        return 0.0;
    }
};
