// Last updated: 3/25/2026, 9:04:41 AM
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        int rows = image.size();
        int cols = image[0].size();
        if (oldColor != color) // avoid infinite recursion
            dfs(sr, sc, rows, cols, image, color, oldColor);
        return image;
    }

private:
    void dfs(int sr, int sc, int rows, int cols, vector<vector<int>>& image, int newColor, int oldColor) {
        if (sr < 0 || sc < 0 || sr >= rows || sc >= cols || image[sr][sc] != oldColor)
            return;

        image[sr][sc] = newColor;

        dfs(sr - 1, sc, rows, cols, image, newColor, oldColor);
        dfs(sr + 1, sc, rows, cols, image, newColor, oldColor);
        dfs(sr, sc - 1, rows, cols, image, newColor, oldColor);
        dfs(sr, sc + 1, rows, cols, image, newColor, oldColor);
    }
};
