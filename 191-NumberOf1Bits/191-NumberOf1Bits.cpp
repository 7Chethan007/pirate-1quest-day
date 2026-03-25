// Last updated: 3/25/2026, 9:06:13 AM
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n > 0) {
            n = n & (n-1);
            count++;
        }
        return count;
    }
};