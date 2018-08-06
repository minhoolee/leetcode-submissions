/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (29.33%)
 * Total Accepted:    255.5K
 * Total Submissions: 871.3K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 * Example 1:
 *
 *
 * Input: 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 * the decimal part is truncated, 2 is returned.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Optimal approach
 *
 *  Use Newton's method and sqrt(x) function to find root
 *
 *  let f(r) = r^2 - x = 0, r(n) = n'th attempt to find square root
 *
 *  r(n+1) = r(n) - f(r(n)) / f'(r(n))
 *  r(n+1) = r(n) - (r(n)^2 - x) / (2 * r(n))
 *  r(n+1) = r(n) - r(n)/2 + x / (2 * r(n))
 *  r(n+1) = (r(n) + x / r(n)) / 2
 *
 *  Time: O(logn)
 *  Space: O(1)
 *
 *  mySqrt(x):
 *    // Initial guess must be <= x due to possible overflow
 *    set root to x
 *
 *    // See proof
 *    while root^2 > x
 *      set root to (root + x/root) / 2
 *
 *    return root
 */
class Solution {
 public:
  int mySqrt(int x) {
    long r = x;

		while (r*r > x) {
			r = (r + x/r) / 2;
		}

		return r;
  }
};
