// Last updated: 3/25/2026, 9:03:50 AM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int r = rows - 1, c = 0, count = 0;

        while (r >= 0 && c < cols) {
            if (grid[r][c] < 0) {
                count += cols - c; 
                r--;
            } else {
                c++;
            }
        }
        return count;
    }
};
