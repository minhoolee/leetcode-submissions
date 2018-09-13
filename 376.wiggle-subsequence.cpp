/*
 * [376] Wiggle Subsequence
 *
 * https://leetcode.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (36.28%)
 * Total Accepted:    37.8K
 * Total Submissions: 104.3K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * A sequence of numbers is called a wiggle sequence if the differences between
 * successive numbers strictly alternate between positive and negative. The
 * first difference (if one exists) may be either positive or negative. A
 * sequence with fewer than two elements is trivially a wiggle sequence.
 *
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
 * (6,-3,5,-7,3) are alternately positive and negative. In contrast,
 * [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its
 * first two differences are positive and the second because its last
 * difference is zero.
 *
 * Given a sequence of integers, return the length of the longest subsequence
 * that is a wiggle sequence. A subsequence is obtained by deleting some number
 * of elements (eventually, also zero) from the original sequence, leaving the
 * remaining elements in their original order.
 *
 * Example 1:
 *
 *
 * Input: [1,7,4,9,2,5]
 * Output: 6
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [1,2,3,4,5,6,7,8,9]
 * Output: 2
 *
 * Follow up:
 * Can you do it in O(n) time?
 *
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Greedy
 *
 *  Time: O(n)
 *  Space: O(1)
 */
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();

    int prev_diff = nums[1] - nums[0];

    // Add first num if next diff is not 0 (prev diff can be opposite sign)
    int count = prev_diff == 0 ? 0 : 1;
    for (int i = 1; i < nums.size() - 1; ++i) {
      int next_diff = nums[i + 1] - nums[i];
      if ((next_diff > 0 && prev_diff <= 0) ||
          (next_diff < 0 && prev_diff >= 0)) {
        ++count;
        prev_diff = next_diff;
      }
    }
    // Add last num which is always in wiggle sequence
    ++count;
    return count;
  }
};
