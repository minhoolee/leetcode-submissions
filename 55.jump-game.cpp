/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (30.11%)
 * Total Accepted:    189.2K
 * Total Submissions: 628K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Determine if you are able to reach the last index.
 *
 * Example 1:
 *
 *
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
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
 *  This problem is a pretty easy DP (tab) problem. However, as shown by how
 *  the greedy solution is far faster, I should always check to see if
 *  optimizations can be made to potentially even get rid of dp.
 *
 *  The solution lists a pretty nice 4 step process
 *
 *  1. Start with the recursive backtracking solution
 *  2. Optimize by using a memoization table (top-down dynamic programming)
 *  3. Remove the need for recursion (bottom-up dynamic programming)
 *  4. Apply final tricks to reduce the time / memory complexity
 */

/**
 *  Test cases
 *
 *  [] => false
 *  [1] => true
 *  [1, 2] => true
 */

/**
 *  DP (tab)
 *
 *  Start from end and dp[i] = can last index be reached from nums[i]
 *
 *  Time: O(n^2)
 *  Space: O(n)
 */
/**
 * class Solution {
 *  public:
 *   bool canJump(vector<int>& nums) {
 *     int n = nums.size();
 *     if (n == 0) return false;
 *
 *     vector<int> dp(n, false);
 *     dp[n - 1] = true;
 *
 *     for (int i = n - 2; i >= 0; --i) {
 *       int jump = nums[i];
 *       // Try each jump from 1 to jump length (nums[i])
 *       for (int j = i + 1; j <= min(i + jump, n - 1) && !dp[i]; ++j) {
 *         dp[i] = dp[j];
 *       }
 *     }
 *     return dp[0];
 *   }
 * };
 */

/**
 *  Greedy
 *
 *  Keep track of leftmost position that can reach end. This comes from
 *  the observation that dp[i] breaks loop the first time it is true
 *
 *  Time: O(n)
 *  Space: O(1)
 */

 class Solution {
  public:
   bool canJump(vector<int>& nums) {
     int n = nums.size();
     if (n == 0) return false;

     int last_pos = n - 1;
     for (int i = n - 1; i >= 0; --i) {
       if (i + nums[i] >= last_pos) {
         last_pos = i;
       }
     }
     return last_pos == 0;
   }
 };
