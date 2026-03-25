// Last updated: 3/25/2026, 9:08:03 AM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If no strings, no common prefix
        if (strs.empty()) return "";
        string  res = "";

        // Compare char's position by ussing the 1st strings position
        
        // iterate only for the number of time the first ele size
        for(int i = 0; i < strs[0].size(); i++) { 
            char ch = strs[0][i];

            // Check this particular chr if present in all the strings
            for(int j = 0; j < strs.size(); j++) {
                // Stop if a string ends or characters differ
                if (i == strs[j].size() || strs[j][i] != ch) {
                    // if any ele (other than 0th) is small in that case at the point exit 
                    // i == strs[i].size()
                    return res;
                }
            }
                // Character matches in all strings
                res += ch;
        }
        return res;
    }
};