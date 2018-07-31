/*
 * [390] Elimination Game
 *
 * https://leetcode.com/problems/elimination-game/description/
 *
 * algorithms
 * Medium (42.74%)
 * Total Accepted:    18.2K
 * Total Submissions: 42.6K
 * Testcase Example:  '9'
 *
 *
 * There is a list of sorted integers from 1 to n. Starting from left to right,
 * remove the first number and every other number afterward until you reach the
 * end of the list.
 *
 * Repeat the previous step again, but this time from right to left, remove the
 * right most number and every other number from the remaining numbers.
 *
 * We keep repeating the steps again, alternating left to right and right to
 * left, until a single number remains.
 *
 * Find the last number that remains starting with a list of length n.
 *
 * Example:
 *
 * Input:
 * n = 9,
 * 1 2 3 4 5 6 7 8 9
 * 2 4 6 8
 * 2 6
 * 6
 *
 * Output:
 * 6
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
 *  Store values in vector and ignore every other number from left or right
 *  based on step counter
 *
 *  Time: O(logn)
 *  Space: O(n)
 */

/**
 *  Second approach
 *
 *  Try to unroll and compress steps into single mathematical solution
 *  Doesn't seem like there is a pattern
 *
 *  n = 22
 *  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 24 => n = 24 => n
 *  2 4 6 8 10 12 14 16 18 20 22 24 => n = 12 => 2n
 *  2 6 10 14 18 22 => n = 6 => 2n + 2(n-1)
 *  6 14 22 => n = 3 => ??
 *  14 => n = 1
 */

/**
 *  Optimal approach
 *
 *  Step forwards with head, depending on length and step count
 *
 *  Time: O(logn)
 *  Space: O(1)
 *
 *  lastRemaining(n):
 *    set left to true
 *    set step to 1
 *    set head to 1
 *    while n > 1
 *      if left or n is odd
 *        add step to head
 *      set n to n/2
 *      set step to 2*step
 *      flip left's value
 *    return head
 */

/**
 *  Clever approach
 *
 *  Recursively determine steps and use mirror property to switch between
 *  leftwards and rightwards removal
 *
 *  Time: O(logn)
 *  Space: O(logn)
 *
 *  lastRemaining(n):
 *    if n equals 1
 *      return 1
 *    else
 *      // Mirror property is that reversing list across the center and
 *      // subtracting from n + 1 (every pair of values across the center
 *      // sums to n + 1) will result in removal in the opposite direction
 *      return 2 * ((n/2 + 1) - lastRemaining(n/2))
 */

/**
 *  Test cases
 *
 *  n = {1} => 1
 *  n = {2,3,4,5} => 2
 *  n = {6,7} => 4
 *  n = {8,9,10,11,12,13,14,15,16,17} => 6
 */
class Solution {
 public:
  int lastRemaining(int n) {
    return n == 1 ? 1 : 2 * ((n/2 + 1) - lastRemaining(n/2));
  }
};
