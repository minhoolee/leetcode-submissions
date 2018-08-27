/*
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (37.73%)
 * Total Accepted:    60K
 * Total Submissions: 158.8K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 *
 * Example 1:
 *
 *
 * Input: nums =
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: nums =
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  DFS + DP (memo)
 *
 *  DFS on each cell and memo the longest path length for each cell
 *
 *  Time: O(m*n)
 *  Space: O(m*n)?
 */

/**
 *  Test cases
 *
 *  empty => 0
 *  Ex. 1 => 4
 *  Ex. 2 => 4
 */
class Solution {
 private:
  const vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

  int DFS(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j,
          int m, int n) {
    if (memo[i][j] != 0) return memo[i][j];

    for (const auto& path : directions) {
      int r = i + path[0], c = j + path[1];
      if (r < 0 || r >= m || c < 0 || c >= n || matrix[i][j] >= matrix[r][c])
        continue;
      memo[i][j] = max(memo[i][j], 1 + DFS(matrix, memo, r, c, m, n));
    }

    if (memo[i][j] == 0) memo[i][j] = 1;
    return memo[i][j];
  }

 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));

    int max_len = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        max_len = max(max_len, DFS(matrix, memo, i, j, m, n));
      }
    }

    return max_len;
  }
};
