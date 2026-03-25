// Last updated: 3/25/2026, 9:05:59 AM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to keep track of the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);          // Push current number
            if (minHeap.size() > k) {   // Keep only k elements in heap
                minHeap.pop();          // Remove the smallest
            }
        }

        // Top of the heap = kth largest element
        return minHeap.top();
    }
};