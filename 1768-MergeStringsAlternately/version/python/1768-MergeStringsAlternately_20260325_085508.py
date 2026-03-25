# Last updated: 3/25/2026, 8:55:08 AM
1class Solution:
2    def mergeAlternately(self, word1: str, word2: str) -> str:
3        # Take two pointes at the beginning of each sting
4        i = j = 0
5        merged = []
6
7        # Update merged sting 1 from word1 thne from word 2
8        # Do this till the any one of the sting gets exhaused
9        while i < len(word1) and j < len(word2):
10            merged.append(word1[i])
11            merged.append(word2[j])
12            i += 1
13            j += 1
14
15        # Then in the end which one exists merge the rest as it is
16        # into the merged string form that index
17        merged.append(word1[i:])
18        merged.append(word2[j:])
19
20        return "".join(merged)
21
22        
23
24
25
26
27
28
29
30# Take two pointes at the beginning of each sting
31
32# Update merged sting 1 from word1 thne from word 2
33# Do this till the any one of the sting gets exhaused
34
35# Then in the end which one exists merge the rest as it is
36# into the merged string form that index
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75