// Last updated: 3/25/2026, 9:03:33 AM
class Solution {
    public int maximumWealth(int[][] accounts) {
        int m = accounts.length;
        int ans = 0;
        int[] a = new int[m];
        for(int i = 0; i < m ; i++) {
            int n = accounts[i].length;
            for(int j = 0; j < n; j++) {
                a[i] += accounts[i][j];
            }
        }

        for(int i = 0 ; i< m ; i++) {
            if(a[i] > ans) {
                ans = a[i];
            }
        }

        return ans; 
    }
}