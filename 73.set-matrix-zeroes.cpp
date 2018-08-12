/*
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (37.28%)
 * Total Accepted:    153.8K
 * Total Submissions: 412.4K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output:
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output:
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 *
 *
 * Follow up:
 *
 *
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Note: O(1) space means no data structures or even recursion
 *
 *  Trick to this problem is saving row and column in cells that
 *  will not be visited again
 */

/**
 *  State-saving approach
 *
 *  Traverse matrix while saving state of row and col in visited border cells
 *
 *  Time: O(n^2)
 *  Space: O(1)
 *
 *  setZeros(matrix):
 *    // Extra memory is needed for first column because matrix[0][0] tracks
 *    // both first row and first column
 *    set isFirstCol0 to false
 *
 *    // Traverse matrix and store states of rows and cols in visited
 *    // border cells
 *    for r in [0..rows)
 *      if matrix[r][0] = 0
 *        set isFirstCol0 to true
 *
 *      for c in [1..cols)
 *        if matrix[r][c] = 0
 *          set matrix[0][c], matrix[r][0] to 0
 *
 *    // Traverse matrix in reverse in order to maintain row and col flags
 *    for r in (rows..0]
 *      for c in (cols..1]
 *        if matrix[0][c] = 0 or matrix[r][0] = 0
 *          set matrix[r][c] to 0
 *
 *      if isFirstCol0
 *        set matrix[r][0] to 0
 *
 */
class Solution {
 public:
  void setZeroes(vector< vector<int> >& matrix) {
    bool isFirstCol0 = false;
    int rows = matrix.size(), cols = matrix[0].size();

    for (int r = 0; r < rows; ++r) {
      if (matrix[r][0] == 0) isFirstCol0 = true;

      for (int c = 1; c < cols; ++c)
        if (matrix[r][c] == 0)
          matrix[0][c] = matrix[r][0] = 0;
    }

    for (int r = rows - 1; r >= 0; --r) {
      for (int c = cols - 1; c >= 1; --c)
        if (matrix[0][c] == 0 || matrix[r][0] == 0)
          matrix[r][c] = 0;

      if (isFirstCol0) matrix[r][0] = 0;
    }
  }
};
