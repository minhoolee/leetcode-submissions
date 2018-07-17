/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (37.12%)
 * Total Accepted:    356.1K
 * Total Submissions: 959.4K
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Could you solve it without converting the integer to a string?
 * 
 */
class Solution {
public:
  // Test cases:
  // 121 -> true
  // -121 -> false (cannot be negative)
  // 10 -> false (not 010)
  // 17233271 -> true
  // 0 -> true
  bool isPalindrome(int x) {
    // Return false if negative number or end with 0 (cannot be palindrome)
    if ((x < 0)|| (x % 10 == 0 && x != 0)) return false;

    // Set rev to 0
    int rev = 0;

    // Loop until half of the number (rev < x)
    while (rev < x) {
      // Pop off last digit of x and push to end of rev
      rev = rev * 10 + (x % 10);
      x /= 10;
    }

    // Return true if rev equals x or rev/10 equals x (for odd palindromes)
    return (rev == x || rev/10 == x);
  }
};
