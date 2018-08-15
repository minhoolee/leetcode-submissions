/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (42.91%)
 * Total Accepted:    241.7K
 * Total Submissions: 562.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
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
 *  Backtrack all sets (including element duplicates), breaking if sum > target
 *
 *  Time: O(n*2^n) ?
 *  Space: O(2^n) ?
 *
 *  backtrack(subs, sub, candidates, start, target):
 *    // Backtrack because sum > target
 *    if target < 0
 *      return
 *    else if target == 0
 *      add sub to subs
 *    else
 *      for i in [start..candidates' size)
 *        // candidates is sorted so we can exit loop early
 *        if candidates[i] > target
 *          return
 *
 *        add candidates[i] to sub
 *        // Set start to i because there can be element duplicates
 *        backtrack(subs, sub, candidates, i, target - candidates[i]
 *        remove subs' last element
 *
 *  combinationSum(candidates, target):
 *    init subs as empty array of arrays
 *    init sub as empty array
 *
 *    // Sort in order to exit early if subsequent elements > remaining target
 *    sort candidates
 *    backtrack(subs, sub, candidates, 0, target)
 *
 *    return subs
 */
class Solution {
 private:
  void backtrack(vector<vector<int>>& subs, vector<int>& sub,
                 vector<int>& candidates, int start, int target) {
    if (target < 0)
      return;
    else if (target == 0)
      subs.push_back(sub);
    else {
      for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] > target) return;
        sub.push_back(candidates[i]);
        backtrack(subs, sub, candidates, i, target - candidates[i]);
        sub.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> subs;
    vector<int> sub;

    std::sort(candidates.begin(), candidates.end());
    backtrack(subs, sub, candidates, 0, target);

    return subs;
  }
};
