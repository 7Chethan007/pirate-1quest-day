// Last updated: 3/25/2026, 9:05:47 AM
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; 
        unordered_map<char, int> myFreq;
        // Create Hashmaps with frequency of characters
        for(char c : s) {
            myFreq[c]++;
        }
        for(char c : t) {
            // find that character in hashmap and reduce it's frequency
            if(myFreq.find(c) == myFreq.end()){
                return false; // If char not found at all -> direct false 
            }
            myFreq[c]--;
        }
        // In the end iterate through the hashmap and if any characters frequency is above 0 return false
        // for(char c : myFreq) {
        //     if(myFreq.at[c] > 0) return false;
        // }
        for (auto &p : myFreq) {
            if (p.second != 0) return false;
        }

        return true;
    }
};