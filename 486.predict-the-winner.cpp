/*
 * [486] Predict the Winner
 *
 * https://leetcode.com/problems/predict-the-winner/description/
 *
 * algorithms
 * Medium (45.35%)
 * Total Accepted:    32.5K
 * Total Submissions: 71.6K
 * Testcase Example:  '[1,5,2]'
 *
 * Given an array of scores that are non-negative integers. Player 1 picks one
 * of the numbers from either end of the array followed by the player 2 and
 * then player 1 and so on. Each time a player picks a number, that number will
 * not be available for the next player. This continues until all the scores
 * have been chosen. The player with the maximum score wins.
 *
 * Given an array of scores, predict whether player 1 is the winner. You can
 * assume each player plays to maximize his score.
 *
 * Example 1:
 *
 * Input: [1, 5, 2]
 * Output: False
 * Explanation: Initially, player 1 can choose between 1 and 2. If he chooses 2
 * (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5,
 * then player 1 will be left with 1 (or 2). So, final score of player 1 is 1 +
 * 2 = 3, and player 2 is 5. Hence, player 1 will never be the winner and you
 * need to return False.
 *
 *
 *
 * Example 2:
 *
 * Input: [1, 5, 233, 7]
 * Output: True
 * Explanation: Player 1 first chooses 1. Then player 2 have to choose between
 * 5 and 7. No matter which number player 2 choose, player 1 can choose
 * 233.Finally, player 1 has more score (234) than player 2 (12), so you need
 * to return True representing player1 can win.
 *
 *
 *
 * Note:
 *
 * 1
 * Any scores in the given array are non-negative integers and will not exceed
 * 10,000,000.
 * If the scores of both players are equal, then player 1 is still the winner.
 *
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
 *  Fill n x n table such that dp[i][j] = score difference that player one
 *  achieves from nums[i:j]. Each move is decided by cell below and left of
 *  current cell: max(nums[i] - nums[i+1][j], nums[j] - nums[i][j-1])
 *
 *  Key point is understand what the table represents (not boolean!)
 *
 *  Time: O(n^2)
 *  Space: O(n^2)
 *
 *  PredictTheWinner(nums):
 *    set n to nums.size
 *    set dp to empty array of arrays of size n by n initialized to 0
 *
 *    for i in (n..0]:
 *      set dp[i][i] to nums[i]
 *      for j in [i+1..n):
 *        set a to nums[i] - dp[i + 1][j]
 *        set b to nums[j] - dp[i][j - 1]
 *        set dp[i][j] to max(a, b)
 *
 *    return dp[0][n - 1] >= 0
 */

/**
 *  DP (tab) approach
 *
 *  DP (tab) but use 1D array because rows can be flattened to time steps
 *
 *  Time: O(n^2)
 *  Space: O(n)
 *
 *  PredictTheWinner(nums):
 *    set n to nums.size
 *    set dp to empty array of size n initialized to 0
 *
 *    for i in (n..0]:
 *      set dp[i] to nums[i]
 *      for j in [i+1..n):
 *        set a to nums[i] - dp[j]
 *        set b to nums[j] - dp[j - 1]
 *        set dp[j] to max(a, b)
 *
 *    return dp[n - 1] >= 0
 */
class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    if (nums.empty()) return false;

    int n = nums.size();
    vector<int> dp(n, 0);

    for (int i = n - 1; i >= 0; --i) {
      dp[i] = nums[i];
      for (int j = i + 1; j < n; ++j) {
        int a = nums[i] - dp[j];
        int b = nums[j] - dp[j - 1];
        dp[j] = max(a, b);
      }
    }

    return dp[n - 1] >= 0;
  }
};
