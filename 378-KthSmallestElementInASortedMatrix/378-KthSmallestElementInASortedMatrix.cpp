// Last updated: 3/25/2026, 9:05:23 AM
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // Max-heap
        priority_queue<int> maxHeap;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxHeap.push(matrix[i][j]);
                if (maxHeap.size() > k) {
                    maxHeap.pop(); // remove the largest
                }
            }
        }

        return maxHeap.top(); // kth smallest
    }
};
