// Last updated: 3/25/2026, 9:03:35 AM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();if(rows == 0) return 0;
        int cols = heights[0].size();
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; 
        // {diff, r, c}

        pq.push({0,0,0});
        effort[0][0] = 0;

        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int diff = cur[0], r = cur[1], c = cur[2];
            if(r == rows - 1 && c == cols - 1) return diff;
            if(diff > effort[r][c]) continue;

            for(auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                int newDiff = max(diff, abs(heights[r][c] - heights[nr][nc]));
                if(newDiff < effort[nr][nc]) {
                    effort[nr][nc] = newDiff;
                    pq.push({newDiff, nr, nc});
                }
            }
        }
        return 0;
    }
};