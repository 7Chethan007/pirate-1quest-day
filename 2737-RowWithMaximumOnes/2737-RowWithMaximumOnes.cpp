// Last updated: 3/25/2026, 9:02:59 AM
class Solution {
public:

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int cnt_max = -1, index = -1;
        int n = mat.size();       // number of rows
        int m = mat[0].size();    // number of columns

        for(int i = 0; i < n; i++) {
            int cnt_ones = 0;
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    cnt_ones++;
                }
            }
            if(cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return {index, cnt_max};
    }
};