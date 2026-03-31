# Last updated: 3/31/2026, 8:47:48 AM
1from typing import List
2
3class Solution:
4    def compress(self, chars: List[str]) -> int:
5        n = len(chars)
6        write = 0  # Where we write the result
7        read = 0   # Where we read the current character
8        
9        while read < n:
10            char_to_compress = chars[read]
11            count = 0
12            
13            # Count occurrences of the current character
14            while read < n and chars[read] == char_to_compress:
15                read += 1
16                count += 1
17            
18            # 1. Write the character
19            chars[write] = char_to_compress
20            write += 1
21            
22            # 2. Write the count if it's greater than 1
23            if count > 1:
24                for digit in str(count):
25                    chars[write] = digit
26                    write += 1
27                    
28        return write