// Last updated: 3/25/2026, 9:05:29 AM
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Min-heap of size k
        // pair = (frequency, element)
        // auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
        //     return a.first > b.first; // smallest freq at top
        // };
        // priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for (auto& entry : freq) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 3: Extract elements
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
