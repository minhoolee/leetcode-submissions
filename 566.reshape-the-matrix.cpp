/*
 * [566] Reshape the Matrix
 *
 * https://leetcode.com/problems/reshape-the-matrix/description/
 *
 * algorithms
 * Easy (57.83%)
 * Total Accepted:    58.8K
 * Total Submissions: 101.6K
 * Testcase Example:  '[[1,2],[3,4]]\n1\n4'
 *
 * In MATLAB, there is a very useful function called 'reshape', which can
 * reshape a matrix into a new one with different size but keep its original
 * data.
 *
 *
 *
 * You're given a matrix represented by a two-dimensional array, and two
 * positive integers r and c representing the row number and column number of
 * the wanted reshaped matrix, respectively.
 *
 * ⁠The reshaped matrix need to be filled with all the elements of the
 * original matrix in the same row-traversing order as they were.
 *
 *
 *
 * If the 'reshape' operation with given parameters is possible and legal,
 * output the new reshaped matrix; Otherwise, output the original matrix.
 *
 *
 * Example 1:
 *
 * Input:
 * nums =
 * [[1,2],
 * ⁠[3,4]]
 * r = 1, c = 4
 * Output:
 * [[1,2,3,4]]
 * Explanation:The row-traversing of nums is [1,2,3,4]. The new reshaped matrix
 * is a 1 * 4 matrix, fill it row by row by using the previous list.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * nums =
 * [[1,2],
 * ⁠[3,4]]
 * r = 2, c = 4
 * Output:
 * [[1,2],
 * ⁠[3,4]]
 * Explanation:There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So
 * output the original matrix.
 *
 *
 *
 * Note:
 *
 * The height and width of the given matrix is in range [1, 100].
 * The given r and c are all positive.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Notes for improvement
 *
 *  I suprisingly had a lot of trouble with this problem. Even though I knew
 *  the trick is that a 1D array can encode a 2D array with mod, I kept
 *  getting confused. What finally made it make sense was understanding the
 *  program's abstract flow. 
 *  Aka: row increases when ... and col increases when ...
 *
 *  I kept trying to solve the problem using test cases that only gave one
 *  half of the flow (1x4 -> 2x2 and 2x2 -> 1x4). Don't do this.
 */

/**
 *  Math
 *
 *  N = r * c = r_0 * c_0
 *  Keep track of wraps
 *  Row increases when wrap hits c
 *  Col increases until wrap hits c
 *
 *  Time: O(m * n)
 *  Space: O(1)
 */
class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if (nums.empty() || r * c != nums.size() * nums[0].size()) return nums;

    vector<vector<int>> res(r, vector<int>(c, 0));
    int wrap_ind = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < nums[0].size(); ++j) {
        res[wrap_ind / c][wrap_ind % c] = nums[i][j];
        wrap_ind++;
      }
    }
    return res;
  }
};
