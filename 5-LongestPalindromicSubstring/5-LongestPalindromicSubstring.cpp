// Last updated: 3/25/2026, 9:08:12 AM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // expand around center [l, r], return length
    int expand(const string &s, int l, int r) {
        int n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l; ++r;
        }
        return r - l - 1;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int bestStart = 0, bestLen = 1;
        for (int i = 0; i < n; ++i) {
            // odd length center at i
            int len1 = expand(s, i, i);
            if (len1 > bestLen) {
                bestLen = len1;
                bestStart = i - (len1 - 1) / 2;
            }
            // even length center between i and i+1
            int len2 = expand(s, i, i + 1);
            if (len2 > bestLen) {
                bestLen = len2;
                bestStart = i - (len2 / 2) + 1;
            }
        }
        return s.substr(bestStart, bestLen);
    }
};

