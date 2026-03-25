// Last updated: 3/25/2026, 9:05:37 AM
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> arr;
        string word;
        istringstream iss(s);

        while (iss >> word) {
            arr.push_back(word);
        }

        if (pattern.size() != arr.size()) return false;

        unordered_map<char, string> map;
        unordered_set<string> used;

        for (int i = 0; i < arr.size(); i++) {
            char c = pattern[i];
            string s1 = arr[i];

            if (map.find(c) != map.end()) { // already mapped
                if (map[c] != s1) return false;
            } else {
                if (used.count(s1)) return false; // word already mapped to another char
                map[c] = s1;
                used.insert(s1);
            }
        }
        return true;
    }
};
