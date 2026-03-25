// Last updated: 3/25/2026, 9:06:45 AM
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while (start < end) {
            if (!myIsAlnum(s[start])) { start++; continue; }
            if (!myIsAlnum(s[end]))   { end--;   continue; }

            if (tolower(s[start]) != tolower(s[end])) return false;

            start++;
            end--;
        }
        return true;
    }

private:
    bool myIsAlnum(char c) {
        return (c >= '0' && c <= '9') ||
               (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z');
    }
};
