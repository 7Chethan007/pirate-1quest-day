# Last updated: 3/25/2026, 9:03:22 AM
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        # Take two pointes at the beginning of each sting
        i = j = 0
        merged = []

        # Update merged sting 1 from word1 thne from word 2
        # Do this till the any one of the sting gets exhaused
        while i < len(word1) and j < len(word2):
            merged.append(word1[i])
            merged.append(word2[j])
            i += 1
            j += 1

        # Then in the end which one exists merge the rest as it is
        # into the merged string form that index
        merged.append(word1[i:])
        merged.append(word2[j:])

        return "".join(merged)

        







# Take two pointes at the beginning of each sting

# Update merged sting 1 from word1 thne from word 2
# Do this till the any one of the sting gets exhaused

# Then in the end which one exists merge the rest as it is
# into the merged string form that index






































