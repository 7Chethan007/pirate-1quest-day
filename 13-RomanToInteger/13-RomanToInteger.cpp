// Last updated: 3/25/2026, 9:08:04 AM
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Creat a map data structure
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        // 2 variable total and pV i.e., previousValue
        int total = 0;
        int pV= 0;

        // Iterate from righ to left and if left val PRESENT val is smaller than right PREVIOUS val
        // then subtract it's value from total
        // if PRESENT val is greate than PREVIOUS val include it to total
        for(int i = s.size() - 1; i >= 0; i--) {
            int val = romanMap[s[i]];   // Present val
            if(val < pV) {
                total -= val;
            }
            else {
                total += val;
            }
            // Keep track of this val thus it can be used for comparision in next iteration
            pV= val;
        }
        return total;
    }

};
