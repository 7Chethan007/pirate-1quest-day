// Last updated: 3/25/2026, 9:07:45 AM
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long INT_MAX_ = (1LL << 31) - 1;
        long long INT_MIN_ = -(1LL << 31);

        // Overflow case
        if (dividend == INT_MIN_ && divisor == -1)
            return INT_MAX_;

        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long and use negative numbers
        long long dvd = -llabs(dividend);
        long long dvs = -llabs(divisor);

        long long quotient = 0;

        // Try all bit positions from 31 down to 0
        for (int i = 31; i >= 0; i--) {
            // Check if (dvs << i) fits into dvd
            if (dvd <= (dvs << i)) {
                dvd -= (dvs << i);
                quotient |= (1LL << i);
            }
        }

        return negative ? -quotient : quotient;
    }
};