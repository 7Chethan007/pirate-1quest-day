// Last updated: 3/25/2026, 9:05:24 AM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // Min-heap: (sum, i, j)
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        // Push first row (nums1[0] + nums2[j])
        for (int j = 0; j < nums2.size() && j < k; j++) {
            minHeap.push({nums1[0] + nums2[j], 0, j});
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            result.push_back({nums1[i], nums2[j]});

            if (i + 1 < nums1.size()) {
                minHeap.push({nums1[i+1] + nums2[j], i+1, j});
            }
        }

        return result;
    }
};