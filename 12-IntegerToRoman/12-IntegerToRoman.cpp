// Last updated: 3/25/2026, 9:08:05 AM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // All possible Roman numeral values and their symbols
        vector<int> values   = {1000, 900, 500, 400,
                                100,  90,  50,  40,
                                10,   9,   5,   4,
                                1};
        vector<string> symbols = {"M",  "CM", "D",  "CD",
                                  "C",  "XC", "L",  "XL",
                                  "X",  "IX", "V",  "IV",
                                  "I"};

        string result;

        for (int i = 0; i < (int)values.size() && num > 0; ++i) {
            while (num >= values[i]) {
                num -= values[i];
                result += symbols[i];
            }
        }

        return result;
    }
};
