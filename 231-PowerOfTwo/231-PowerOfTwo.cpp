// Last updated: 3/25/2026, 9:05:55 AM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};