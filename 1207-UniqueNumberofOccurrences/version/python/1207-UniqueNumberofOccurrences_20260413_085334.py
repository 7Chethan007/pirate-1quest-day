# Last updated: 4/13/2026, 8:53:34 AM
# Write own counter and iterate with an example
1from collections import Counter
2
3class Solution:
4    def closeStrings(self, word1: str, word2: str) -> bool:
5        # Check if both words are of same length, if not return False
6        # Check if both words have same alphabets (by comparing set(word1) and set(word2)
7        # Make two lists having count of all alphabets one for word1 and one for word2, sort the lists, check if the lists are equal, if yes return True, else return False
8        # Rule 1: Check length
9        if len(word1) != len(word2):
10            return False
11        
12        # Count frequencies of characters in both words
13        c1 = Counter(word1)
14        c2 = Counter(word2)
15        
16        # Rule 2: Check if they have the same set of unique characters
17        # keys() gives the unique characters present
18        if set(c1.keys()) != set(c2.keys()):
19            return False
20        
21        # Rule 3: Check if the frequency counts are the same
22        # We don't care which letter has which count, just that the 
23        # "bundle" of counts is the same (e.g., [3, 2, 1] vs [1, 2, 3])
24        return sorted(c1.values()) == sorted(c2.values())