// Last updated: 3/25/2026, 9:04:21 AM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Max-heap by default in C++
        priority_queue<int> maxHeap;

        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); maxHeap.pop();
            int stone2 = maxHeap.top(); maxHeap.pop();

            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2);
            }
            // If equal, both are destroyed (do nothing)
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};