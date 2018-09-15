/*
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (28.68%)
 * Total Accepted:    50.7K
 * Total Submissions: 176.7K
 * Testcase Example:
 * '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 *
 *
 *
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 *
 *
 * Example:
 *
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 *
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 *
 *
 *
 * Note:
 *
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Hash Map
 *
 *  Hash all possible sums
 *
 *  Time: O(m * n) build, O(1) query
 *  Space: O(m * n)
 */

/**
 *  DP (tab)
 *
 *  Using (0,0) as reference point,
 *  let dp[i][j] = sum from (0,0 to i-1,j-1)
 *
 *  dp[i][j] = mat[i-1][j-1] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1]
 *  sum(r1, c1, r2, c2) =
 *    dp[r2+1][c2+1] - dp[r2+1][c1] - dp[r1][c2+1] + dp[r1][c1]
 *
 *
 *  Time: O(m * n) build, O(1) query
 *  Space: O(m * n)
 */
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> matrix) {
    if (matrix.empty() || matrix[0].empty()) return;

    int m = matrix.size();
    int n = matrix[0].size();
    sum_to_ = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        sum_to_[i][j] = matrix[i - 1][j - 1] + sum_to_[i][j - 1] +
                        sum_to_[i - 1][j] - sum_to_[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum_to_[row2 + 1][col2 + 1] - sum_to_[row2 + 1][col1] -
           sum_to_[row1][col2 + 1] + sum_to_[row1][col1];
  }

 private:
  vector<vector<int>> sum_to_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
