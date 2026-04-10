# Last updated: 4/10/2026, 9:07:13 AM
1class Solution:
2    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
3        set1 = set(nums1)
4        set2 = set(nums2)
5
6        v1 = set1 - set2
7        v2 = set2 - set1
8
9        return (list(v1), list(v2))