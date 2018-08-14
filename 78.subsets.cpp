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
 *  Note
 *  Time and space complexities for this problem are difficult to calculate;
 *  try to get help on this from someone better.
 */

/**
 *  First, recursive approach
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
 *    init subs to empty array of arrays
 *    init sub to empty array
 *    backtrack(nums, 0, sub, subs)
 *    return subs
 */

/**
 *  Iterative approach
 *
 *  Add next element to copy of all previous subsets
 *
 *  Time: O(n*2^n)
 *  Space: O(2^n)
 *
 *  subsets(nums):
 *    init subs as array of one empty array
 *    for i in [0..nums' size]
 *      set n to subs' size
 *      // Create copies of n existing subsets
 *      // and add new element to each
 *      for j in [0..n]
 *        add sub[j] to subs
 *        add nums[j] to subs' last (added duplicate)
 *    return subs
 */

/**
 *  Bit-manipulation approach
 *
 *  Use bit mask to represent on/off indices of nums
 *
 *  Doesn't scale to n > 32 or 64
 *
 *  Time: O(n*2^n) ?
 *  Space: O(2^n)
 *
 *  subsets(nums):
 *    set n to 2 ^ nums' size
 *    init subs as array of empty arrays
 *
 *    // Bit mask: 0..00, 0..01, 0..10 to 1..11
 *    for b in [0..n]
 *      init sub as empty array
 *      for i in [0..nums' size]
 *        set index to bitshift right b by i
 *        if index bitand 1
 *          add nums[i] to sub
 *      add sub to subs
 *    return subs
 */

/**
 *  DFS (preorder) approach
 *
 *  Construct directed acyclic graph where each node connects to subsequent
 *  nodes but not previous nodes (when iterating through nums). While
 *  traversing the graph with DFS, add node to path and add path to subsets
 *
 *  Time: O(n*2^n) ?
 *  Space: O(n*2^n) ?
 *
 *  dfs(nums, start, path, subs):
 *    add path to subs
 *    for i in [start..nums' size]
 *      dfs(nums, start + 1, path + nums[i], subs)
 *
 *  subsets(nums):
 *    init subs to empty array of arrays
 *    init path to empty array
 *    dfs(nums, 0, path, subs)
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
