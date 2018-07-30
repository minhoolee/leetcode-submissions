/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (40.78%)
 * Total Accepted:    341.1K
 * Total Submissions: 835.1K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Optimal approach
 *
 *  DP: update sum as either value or value + previous subarray
 *  maxSubArray(A, i) =
 *    A[i] + maxSubArray(A, i-1) > 0 ? maxSubArray(A, i-1) : 0
 *
 *  Time: O(n)
 *  Space: O(1)
 *
 *  maxSubArray(nums):
 *    Set sum as 0, max as INT_MIN
 *    For i in nums
 *      If sum > 0
 *        Set sum to sum + A[i]
 *      Else // Get rid of previous subarray
 *        Set sum to A[i]
 *        If sum > max
 *          Set max to sum
 *    Return max
 */

/**
 *  Named optimal approach
 *
 *  Kadane's Algorithm
 *  DP: look for positive subarrays and update max
 *
 *  Time: O(n)
 *  Space: O(1)
 */

/**
 *  Test cases
 *  [1,2,3] => 6
 *  [-1,-2,-3] => -1
 *  [] => N/A (0?)
 *  [0,0,0] => 0
 */
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;
    int sum = 0;
    int max = INT_MIN;

    for (int val : nums) {
      // sum = sum > 0 ? sum + val : val;
      sum = std::max(sum + val, val);
      max = std::max(max, sum);
    }

    return max;
  }
};
