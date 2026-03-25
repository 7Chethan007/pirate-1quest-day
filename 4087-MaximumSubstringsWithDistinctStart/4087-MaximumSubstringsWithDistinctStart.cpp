// Last updated: 3/25/2026, 9:02:19 AM
class Solution {
public:
    int maxDistinct(string s) {
        vector<bool> seen(26, false);
        int count = 0;

        for (char c : s) {
            int idx = c - 'a';
            if (!seen[idx]) {
                seen[idx] = true;
                count++;
            }
        }

        return count;
    }
};
