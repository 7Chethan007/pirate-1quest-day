# Last updated: 4/8/2026, 9:00:32 AM
1class Solution:
2    def largestAltitude(self, gain: List[int]) -> int:
3        current_altitude = 0
4        highest_altitude = 0
5        
6        for g in gain:
7            # Update the current altitude by adding the gain/loss
8            current_altitude += g
9            
10            # Update highest_altitude if the current one is bigger
11            if current_altitude > highest_altitude:
12                highest_altitude = current_altitude
13                
14        return highest_altitude