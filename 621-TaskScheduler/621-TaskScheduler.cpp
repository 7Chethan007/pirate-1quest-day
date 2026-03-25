// Last updated: 3/25/2026, 9:04:50 AM
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequency of each task
        unordered_map<char, int> freq;
        for (char t : tasks) {
            freq[t]++;
        }

        // Step 2: Find maximum frequency
        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        // Step 3: Count how many tasks have this max frequency
        int countMax = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                countMax++;
            }
        }

        // Step 4: Apply formula
        // (maxFreq - 1) * (n + 1) + countMax
        int partCount = (maxFreq - 1) * (n + 1) + countMax;

        // Step 5: Final answer is the maximum of tasks.size() and partCount
        return max((int)tasks.size(), partCount);
    }
};