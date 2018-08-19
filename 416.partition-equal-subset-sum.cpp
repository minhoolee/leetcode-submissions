/*
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (38.61%)
 * Total Accepted:    51.6K
 * Total Submissions: 133.6K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 *
 *
 * Note:
 *
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 *
 *
 *
 * Example 1:
 *
 * Input: [1, 5, 11, 5]
 *
 * Output: true
 *
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 *
 * Example 2:
 *
 * Input: [1, 2, 3, 5]
 *
 * Output: false
 *
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Brute force approach
 *
 *  Generate power set with sums and see if any sum is half of set's sum
 *
 *  Time: O(2^n)
 *  Space: O(2^n)
 */

/**
 *  DP (tab) approach
 *
 *  Subset sum (O/1 knapsack) problem with sum is hal of set's sum
 *
 *  Time: O(nk) where k is sum / 2
 *  Space: O(n) (optimized)
 *
 *  canPartition(nums):
 *    set sum to 0
 *
 *    for i in nums:
 *      add i to sum
 *
 *    if sum is odd
 *      return false
 *
 *    divide sum by 2
 *
 *    init dp to false boolean array of size sum + 1
 *
 *    // Sum is 0 means valid subset was created
 *    set dp[0] to true
 *
 *    // Essentially creates a n x sum matrix except n is across time steps
 *    // This works because row i of 2D matrix always looks at row i-1 only
 *    for num in nums:
 *      for rem in [sum..1]:
 *        // Either excludes num or includes num (and decreases sum)
 *        if rem >= num:
 *          dp[rem] = dp[rem] or dp[rem-num]
 *
 *    return dp[sum]
 */
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;

    for (int num : nums) sum += num;

    if (sum & 1) return false;
    sum /= 2;

    bool dp[sum + 1];
    std::fill_n(dp, sum + 1, false);
    dp[0] = true;

    for (int num : nums) {
      for (int rem = sum; rem > 0; --rem) {
        if (rem >= num) {
          dp[rem] = dp[rem] || dp[rem - num];
        }
      }
    }

    return dp[sum];
  }
};
