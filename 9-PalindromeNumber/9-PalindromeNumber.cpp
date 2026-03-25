// Last updated: 3/25/2026, 9:08:08 AM
class Solution {
public:
    // Without converting to string
    bool isPalindrome(int x) {
        // Negative numbers or numbers ending with 0 (except 0 itself) can’t be palindrome
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;
        while (x > reversedHalf) {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        // For even length numbers: x == reversedHalf
        // For odd length numbers: reversedHalf/10 removes the middle digit
        return (x == reversedHalf || x == reversedHalf / 10);
    }


    // Converting to string
    // bool isPalindrome(int x) {
    //     string s = to_string(x);
    //     string r = s;
    //     reverse(s.begin(), s.end());
    //     return s == r;
    // }
};