/*
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (35.26%)
 * Total Accepted:    30.3K
 * Total Submissions: 86.1K
 * Testcase Example:
 * '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 *
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 *
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 *
 * Note:
 *
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 *
 *
 * Example:
 *
 * Given the following 5x5 matrix:
 *
 * ⁠ Pacific ~   ~   ~   ~   ~
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 *
 * Return:
 *
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  DFS + DP (memo) approach
 *
 *  Flood upwards starting from ocean edges and mark valid paths as visited
 *
 *  Trick is that you start from both oceans and flood upwards. Overlapping
 *  paths indicate water can flow to both oceans.
 *
 *  Time: O(nm)
 *  Space: O(nm)
 *
 *  pacificAtlantic(matrix):
 *    set res to empty list of matrix positions
 *    if matrix is empty:
 *      return res
 *
 *    set m to # of rows, n to # of cols
 *    set pacific to empty boolean matrix of size m by n
 *    set atlantic to empty boolean matrix of size m by n
 *
 *    for r in [0..m):
 *      dfs(matrix, pacific, INT_MIN, r, 0)
 *      dfs(matrix, atlantic, INT_MIN, r, n - 1)
 *
 *    for c in [0..n):
 *      dfs(matrix, pacific, INT_MIN, 0, c)
 *      dfs(matrix, atlantic, INT_MIN, m - 1, c)
 *
 *    for r in [0..m]):
 *      for c in [0..n):
 *        if pacific[r][c] && atlantic[r][c]:
 *          add (r, c) to res
 *
 *    return res
 *
 *  dfs(matrix, visited, height, r, c):
 *    // Path ends if invalid, visited, or flood downwards
 *    if r < 0 or r > # of rows or c < 0 or c > # of rows or visited[r][c]
 *      or matrix[r][c] < height:
 *      return
 *
 *    set visited[r][c] to true
 *
 *    for d in {up, down, left, right}:
 *      dfs(matrix, visited, matrix[r][c], r - d.y, c + d.x)
 */

class Solution {
 private:
  // Up, down, left, right vectors in cartesian plane (x, y)
  vector<pair<int, int>> paths = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

  void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited,
           int height, int r, int c) {
    if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() ||
        visited[r][c] || matrix[r][c] < height)
      return;

    visited[r][c] = true;

    for (auto& d : paths)
      dfs(matrix, visited, matrix[r][c], r - d.second, c + d.first);
  }

 public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<pair<int, int>> res;

    if (matrix.size() == 0 || matrix[0].size() == 0) return res;

    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> pacific (m, vector<bool>(n, false));
    vector<vector<bool>> atlantic (m, vector<bool>(n, false));

    for (int r = 0; r < m; ++r) {
      dfs(matrix, pacific, INT_MIN, r, 0);
      dfs(matrix, atlantic, INT_MIN, r, n - 1);
    }

    for (int c = 0 ; c < n; ++c) {
      dfs(matrix, pacific, INT_MIN, 0, c);
      dfs(matrix, atlantic, INT_MIN, m - 1, c);
    }

    for (int r = 0; r < m; ++r) {
      for (int c = 0 ; c < n; ++c) {
        if (pacific[r][c] && atlantic[r][c]) {
          res.push_back({r, c});
        }
      }
    }

    return res;
  }
};
