/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (46.78%)
 * Total Accepted:    262K
 * Total Submissions: 559.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Recursive approach
 *
 *  Add single elements, then recursively call subsets on n-1 nums, n times
 *
 *  Issue with this pseudocode is that copying is costly, so there should be
 *  a better way even with reference vector in C++
 *
 *  Time: O((2^n)nlogn) ?
 *  Space: O((n^2)logn) ?
 *
 *  helper(nums, toIgnore):
 *    // Base case is when subset is size 2
 *    if nums' size <= 2
 *      return nums
 *
 *    copy nums to subNums
 *    delete subNums[toIgnore]
 *
 *    for [i in 0..subNums' size]
 *      add helper(subNums, i) to subNums
 *
 *    return subNums
 *
 *  subsets(nums):
 *    set sets to empty array of arrays
 *
 *    // Add single elements first in order to avoid duplicates
 *    for element in nums
 *      add element to sets
 *
 *    // Add all possible subsets of size [2..n-1]
 *    for i in [0..nums' size]
 *      add helper(nums, i) to sets
 *
 *    // Add subset of size n
 *    add nums to sets
 *
 *    return sets
 */

/**
 *  Backtracking approach
 *
 *  Backtrack all possible subsets in a bottom up approach
 *
 *  Time: O(2^n) ?
 *  Space: O(2^n) ?
 *
 *  backtrack(nums, start, sub, subs):
 *    add sub to subs
 *    for i in [0..nums' size]
 *      add nums[i] to sub
 *      call backtrack(nums, i + 1, sub, subs)
 *      remove sub's last element
 *
 *  subsubs(nums):
 *    set subs to empty array
 *    set sub to empty array
 *    backtrack(nums, 0, sub, subs)
 *    return subs
 */
class Solution {
 private:
  void backtrack(vector<int>& nums, int start, vector<int>& sub,
                 vector<vector<int>>& subs) {

    subs.push_back(sub);
    for (int i = start; i < nums.size(); ++i) {
      sub.push_back(nums[i]);
      backtrack(nums, i + 1, sub, subs);
      sub.pop_back();
    }
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs;
    vector<int> sub;
    backtrack(nums, 0, sub, subs);
    return subs;
  }
};
