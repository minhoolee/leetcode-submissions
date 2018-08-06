/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (41.69%)
 * Total Accepted:    272.7K
 * Total Submissions: 652.9K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Note: Given n will be a positive integer.
 *
 * Example 1:
 *
 *
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  First approach
 *
 *  Derive mathematical formula
 *
 *  Let a = # of 1 and b = # of 2 such that 1a + 2b = n
 *
 *  It seems there's a pattern where a + b = n-1 or n-2 ... and the number
 *  of these a + b pairs is equal to n/2. Thus, this can be rewritten as
 *  the summation from i = 1 to n/2 of n-i. However, for higher cases it can
 *  be observed that it's not n-i, but it's n-i C b. It is unclear whether b
 *  can be calculated (possibly by calculating all odd values of a, and
 *  subtracting these from n-i).
 *
 *  climbStairs(n):
 *    set sum to 1
 *    for i in [1..n/2]
 *      set sum to sum + (n-i)
 *    if n is even
 *      // Overcount by n-i-1
 *      set sum to sum - (n-n/2-1)
 *    return sum
 *
 * int climbStairs(int n) {
 *   int sum = 1;
 *
 *   for (int i = 1; i <= n / 2; ++i) sum += (n - i);
 *   if (n & 0) sum -= (n - n / 2 - 1);
 *
 *   return sum;
 * }
 */

/**
 *  Brute force approach
 *
 *  Recursively climb up stairs with 1 step and with 2 steps
 *
 *  Time: O(2^n)
 *  Space: O(n)
 *
 *  climbStairs(n):
 *    climbStairsTwice(0, n)
 *
 *  climbStairsTwice(i, n):
 *    if i > n
 *      return 0
 *    if i equals n
 *      return 1
 *    return climbStairsTwice(i+1, n) + climbStairsTwice(i+2, n)
 */

/**
 *  Optimal approach (DP: Memo)
 *
 *  Memoize brute force approach by passing a memo array
 *
 *  Time: O(n)
 *  Space: O(n)
 */

/**
 *  Optimal approach (DP: Tab)
 *
 *  Tabulate brute force approach by taking 1 step from n-1 steps or
 *  2 steps from n-2 steps for all n >= 3
 *
 *  Time: O(n)
 *  Space: O(n)
 *
 *  climbStairs(n):
 *    if n equals 1
 *      return 1
 *
 *    init dp as empty array of size n+1
 *    set dp[1] to 1
 *    set dp[2] to 2
 *    for i in [3..n]
 *      set dp[i] to dp[i-1] + dp[i-2]
 *
 *    return dp[n]
 */

/**
 *  Test cases
 *
 *  n = 6 => 13
 *    1+1+1+1+1+1
 *    1+1+1+1+2
 *    1+1+1+2+1
 *    1+1+2+1+1
 *    1+2+1+1+1
 *    2+1+1+1+1
 *    1+1+2+2
 *    1+2+1+2
 *    2+1+1+2
 *    1+2+2+1
 *    2+1+2+1
 *    2+2+1+1
 *    2+2+2
 */
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) return 1;

    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < n + 1; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }
};
