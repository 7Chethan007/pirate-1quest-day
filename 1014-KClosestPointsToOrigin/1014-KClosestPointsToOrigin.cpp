// Last updated: 3/25/2026, 9:04:30 AM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap: store (distance, {x,y})
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto &p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            maxHeap.push({dist, p});

            // Keep heap size at most k
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Collect result
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};