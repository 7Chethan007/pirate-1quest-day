// Last updated: 3/25/2026, 9:04:24 AM
class Solution {
public:
    int myMax(vector<int>& arr) {
        int maxN = INT_MIN, n = arr.size();
        for(int x : arr) {
            maxN = max(maxN, x);
        }
        return maxN;
    }

    int getSum(vector<int>& arr) {
        int sum = 0, n = arr.size();
        for (int x : arr) {
            sum += x;
        }

        return sum;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = myMax(weights);
        int high = getSum(weights);
        int mid;

        while(low < high) {
            mid = low + (high - low) / 2;
            if(canShip(weights, days, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

private:
    bool canShip(vector<int>& arr, int days, int capacity) {
        int dayCnt = 1, currLoad = 0;
        int n = arr.size();
        for(int w : arr) {
            if(currLoad + w > capacity) {
                dayCnt++;
                currLoad = 0;
            }
            currLoad += w;
            if(dayCnt > days) return false;
        }
        return true;
    }

};