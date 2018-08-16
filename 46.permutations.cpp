/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (49.13%)
 * Total Accepted:    264K
 * Total Submissions: 536.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */
static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Backtracking approach
 *
 *  Backtrack, each time through entire set, checking for duplicates
 *
 *  Effectively brute force solution that stops early each time
 *
 *  Time: O(n^2 * n!) ?
 *  Space: O(n^2)
 *
 *  permute(nums):
 *    set subs to empty list of lists
 *    set sub to empty list
 *    backtrack(subs, sub, nums)
 *    return subs
 *
 *  backtrack(subs, sub, nums):
 *    if sub's size = nums' size
 *      add sub to subs
 *      return
 *
 *    for i in [0..nums' size]
 *      if sub contains nums[i]
 *        continue
 *      add nums[i] to sub
 *      backtrack(subs, sub, nums)
 *      remove sub's last element
 */
class Solution {
 private:
  void backtrack(vector<vector<int>>& subs, vector<int>& sub,
                 vector<int>& nums) {
    if (sub.size() == nums.size()) {
      subs.push_back(sub);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (std::find(sub.begin(), sub.end(), nums[i]) != sub.end()) continue;
      sub.push_back(nums[i]);
      backtrack(subs, sub, nums);
      sub.pop_back();
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> subs;
    vector<int> sub;
    backtrack(subs, sub, nums);
    return subs;
  }
};
