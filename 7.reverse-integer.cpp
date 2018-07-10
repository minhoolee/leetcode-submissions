class Solution {
public:
    // Test cases:
    // 123 -> 321
    // -123 -> -321
    // 2^31 -> 0
    int reverse(int x) {
        // Initialize new number
        int rev = 0;

        // Traverse input until input is 0
        while (x != 0) {
            // Pop off last digit
            int pop = x % 10;
            // Divide remaining input by 10
            x /= 10;

            // Check if new number is greater than INT_MAX/10 or less than INT_MIN/10
            // Check if new number is equal to INT_MAX/10 or INT_MIN/10, and if so
            // if the popped digit is greater than 7 or less than -8
            if (rev > INT_MAX/10 || rev < INT_MIN/10 ||
                (rev == INT_MAX/10 && pop > 7) || (rev == INT_MIN/10 && pop < -8))
                return 0;

            // Add popped digit to 10 times new number
            rev = rev * 10 + pop;
        }
        // Return new number
        return rev;
    }
};
