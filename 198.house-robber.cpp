/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (40.33%)
 * Total Accepted:    229.6K
 * Total Submissions: 569.3K
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 * Example 2:
 *
 *
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  DP (tab) solution
 *
 *  F(0) = A[0]
 *  F(1) = max(A[0], A[1])
 *  F(k) = max( F(k-2) + A[k], F(k-1) )
 *
 *  Somewhat similar to fibonacci
 *
 *  Time: O(n)
 *  Space: O(n)
 *
 *  rob(nums):
 *    set dp to integer array of size of nums initialized to 0
 *
 *    set dp[0] to nums[0]
 *    set dp[1] to max(nums[0], nums[1])
 *
 *    for i in [2..nums.size):
 *      set dp[i] to max(dp[i - 2] + nums[i], dp[i - 1])
 *
 *    return dp[nums.size - 1]
 *
 */
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];

    vector<int> dp (nums.size(), 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); ++i)
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);

    return dp[nums.size() - 1];
  }
};
