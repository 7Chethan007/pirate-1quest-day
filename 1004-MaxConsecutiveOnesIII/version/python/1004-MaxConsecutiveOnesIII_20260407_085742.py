# Last updated: 4/7/2026, 8:57:42 AM
1class Solution:
2    def maxVowels(self, s: str, k: int) -> int:
3        vowels = {'a', 'e', 'i', 'o', 'u'}
4        current_vowels = 0
5        
6        # 1. Build the initial window of size k
7        for i in range(k):
8            if s[i] in vowels:
9                current_vowels += 1
10        
11        max_vowels = current_vowels
12        
13        # 2. Slide the window from index k to the end of the string
14        for i in range(k, len(s)):
15            # Add the character entering the window
16            if s[i] in vowels:
17                current_vowels += 1
18            
19            # Remove the character leaving the window
20            if s[i - k] in vowels:
21                current_vowels -= 1
22            
23            # Update max if current window is better
24            if current_vowels > max_vowels:
25                max_vowels = current_vowels
26            
27            # Optimization: If we hit k, we can't do better, so return early
28            if max_vowels == k:
29                return k
30                
31        return max_vowels