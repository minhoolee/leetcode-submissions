/*
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (44.02%)
 * Total Accepted:    212.7K
 * Total Submissions: 482.8K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 *
 *
 * Example 2:
 *
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  DP (tab) approach
 *
 *  Starting from A[n][m], fill in by sum of right and bottom cells
 *
 *  Time: O(mn)
 *  Space: O(mn)
 *
 *  uniquePaths(m, n):
 *    set dp to empty 2D integer array of size n by m initialized to 1
 *    for i in [n-2..0]:
 *      for j in [m-2..0]:
 *        set dp[i][j] to dp[i][j + 1] + dp[i + 1][j]
 *
 *    return dp[0][0]
 */

/**
 *  DP (tab) approach
 *
 *  Optimize space by using 1D array and timesteps instead of n
 *
 *  Time: O(mn)
 *  Space: O(m)
 *
 *  uniquePaths(m, n):
 *    set dp to empty integer array of size m initialized to 1
 *    for i in [n-2..0]:
 *      for j in [m-2..0]:
 *        set dp[j] to dp[j] + dp[j + 1]
 *
 *    return dp[0]
 */

/**
 *  Combinatoric approach
 *
 *  Robot has to go right m - 1 steps and down n - 1 steps. Each path is 
 *  permutation of R and D steps. This can be rewritten as 
 *
 *  C (m + n, m) 
 *  = (m + n)! / (m! * n!)
 *  = ((m + n) * (m + (n-1)) * .. * (m + 0)!) / (m! * n!)
 *  = ((m + n) * (m + (n-1)) * .. * (m + 1)) / (n!)
 *
 *  which can then be written as a for loop easily
 *
 *  Time: O(min(m,n))
 *  Space: O(1)
 */

/**
 *  Test cases
 *
 *  m = 0, n = 0 => 0
 *  m = 0, n = 1 => 0
 *  m = 1, n = 1 => 1
 *  m = 5, n = 1 => 1
 *  m = 5, n = 2 => 5
 */
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> dp(m, 1);

    for (int i = n - 2; i >= 0; --i) {
      for (int j = m - 2; j >= 0; --j) {
        dp[j] = dp[j] + dp[j + 1];
      }
    }

    return dp[0];
  }
};
