// Last updated: 3/25/2026, 9:03:12 AM
class Solution {
public:
    int maxEle(const vector<vector<int>>& mat, int n, int m, int col) {
        int max_row = 0;
        for (int i = 1; i < n; i++) {
            if (mat[i][col] > mat[max_row][col]) {
                max_row = i;
            }
        }
        return max_row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();               // number of rows
        int m = mat[0].size();              // col
        int low = 0, high = m - 1;
        while(low <= high) {
            int mid = ( low + high ) / 2;
            int row = maxEle(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[row][mid-1] : -1;
            int right = mid + 1 < m ? mat[row][mid+1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if (mat[row][mid] < left) {
                high = mid - 1;  // Move to the left half
            } else {
                low = mid + 1;   // Move to the right half
            }
        }
        return {-1,-1};
    }
};