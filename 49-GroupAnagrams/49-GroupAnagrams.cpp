// Last updated: 3/25/2026, 9:07:30 AM
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            map[key].push_back(word);
        }
        vector<vector<string>> result;
        for(auto &it : map) {
            result.push_back(it.second);
        }
        return result;
    }
};