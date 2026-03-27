# Last updated: 3/27/2026, 8:49:07 AM
1class Solution:
2    def reverseVowels(self, s: str) -> str:
3        # Convert to list because strings are immutable
4        chars = list(s)
5        vowels = set("aeiouAEIOU")
6        i, j = 0, len(chars) - 1
7        
8        while i < j:
9            # Move i forward until it hits a vowel
10            while i < j and chars[i] not in vowels:
11                i += 1
12            # Move j backward until it hits a vowel
13            while i < j and chars[j] not in vowels:
14                j -= 1
15            
16            # Swap the vowels
17            chars[i], chars[j] = chars[j], chars[i]
18            
19            # Move pointers inward to avoid infinite loop
20            i += 1
21            j -= 1
22            
23        return "".join(chars)