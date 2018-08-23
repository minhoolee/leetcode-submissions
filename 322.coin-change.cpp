/*
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (27.10%)
 * Total Accepted:    111.8K
 * Total Submissions: 412.5K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 * Example 1:
 *
 *
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 *
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Backtracking / brute force approach
 *
 *  Subset sum with duplicates (backtrack large -> small)
 *
 *  Time: O(S^n), where S is amount
 *  Space: O(S/c); worse case O(S), where c is lowest coin denomination
 */

/**
 *  DP (tab) approach
 *
 *  Bottom up compute coin counts for sums from [1..S] with and without each
 *  coin denomination
 *
 *  Time: O(S*n)
 *  Space: O(S)
 *
 *  coinChange(coins, amount):
 *    if coins is empty:
 *      return -1
 *
 *    set dp to array of integers of size amount + 1 initialized to INT_MAX - 1
 *    for i in [1..amount]:
 *      for coin in coins:
 *        if coin <= i:
 *          set dp[i] to min(dp[i], dp[i - coin] + 1)
 *
 *    if dp[amount] == INT_MAX - 1:
 *      return dp[amount]
 *    else:
 *      return -1
 */
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (coins.empty())
      return -1;

    // We don't actually need to worry about overflow but might as well
    // for good programming practices
    vector<int> dp (amount + 1, INT_MAX - 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
      for (int coin : coins) {
        if (coin <= i) {
          dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
      }
    }

    return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
  }
};
