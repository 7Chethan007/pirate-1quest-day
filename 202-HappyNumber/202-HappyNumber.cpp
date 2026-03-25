// Last updated: 3/25/2026, 9:06:09 AM
// class Solution {
// public:
//     bool isHappy(int n) {
//         if(n == 1) return true; // if given number itself is 1 then don't mind procedding
// // ERROR : n = 10: next(10) = 1 → one step hits 1 → returns true
//         int slow = sumOfSq(n);
//         int fast = sumOfSq(sumOfSq(n));

//         while(slow != fast) {
//             // TLE : Time limit exceded
//             // as each time redeclaring a new slow and fast pointer 
//             // that diss-appears after each iteration

//             // int slow = sumOfSq(slow);
//             // int fast = sumOfSq(sumOfSq(fast));
//             slow = sumOfSq(slow);
//             fast = sumOfSq(sumOfSq(fast));

//             if(slow == 1 || fast == 1) return true; // Happy number
//         }
//         return false; // Not an happy number 
//         // If it's not an happy no then it would have formed a cycle
//         // then slow and fast will be equal and while would faile 
//     }

// private:
//     int sumOfSq(int num) {
//         int ans = 0;
//         while(num > 0) {
//             int x = num % 10;
//             // ans = ans + (x * x);
//             // num = num / 10;
//             ans += x * x;
//             num /= 10;
//         }
//         return ans;
//     }
// };

class Solution {
    int next(int x) {
        int s = 0;
        while (x > 0) {
            int d = x % 10;
            s += d * d;
            x /= 10;
        }
        return s;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = next(slow);
            fast = next(next(fast));
            if (slow == 1 || fast == 1) return true; // reached 1
        } while (slow != fast);
        return slow == 1; // cycle at 1 => happy; otherwise not
    }
};
