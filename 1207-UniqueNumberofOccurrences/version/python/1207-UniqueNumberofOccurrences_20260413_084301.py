# Last updated: 4/13/2026, 8:43:01 AM
'''
Pretty cool...!
Approach right coding nope
'''

1class Solution:
2    def uniqueOccurrences(self, arr: List[int]) -> bool:
3        # Keep track of the occurance of the number in the array
4        #  -> Hash map key vaule pair 
5        counts = {}
6        for num in arr:
7            counts[num] = counts.get(num, 0) + 1
8        # then for the number of unique number iterate to see if there values are unique or not
9        #  -> if (Value count of Hash map) == (Value count of this value after putting it in set) 
10        #       return true else false
11        occurrence_values = counts.values()
12        return len(occurrence_values) == len(set(occurrence_values))