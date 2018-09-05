/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (28.18%)
 * Total Accepted:    175.8K
 * Total Submissions: 622.9K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 *
 *
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
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
 *  Notes for improvement
 *
 *  When a similar problem can be identified, see if the current
 *  problem can literally build upon the similar problem by calling it
 */

/**
 *  Two Pointer
 *
 *  Three Sum for all nums[i..n) where i = [1..n - 3) with 
 *  target = target - nums[i]
 *
 *  Sort nums, keep track of 4 pointers (a < b < c < d)
 *  Increase order: d then c then b then a depending on
 *  a + b + c + d ? target
 *
 *  Time: O(n^3)
 *  Space: O(1)
 */
/**
 * class Solution {
 *  public:
 *   vector<vector<int>> fourSum(vector<int>& nums, int target) {
 *     if (nums.size() < 4) return {};
 *     int n = nums.size();
 *     int a = 0, d = n - 1;
 *     vector<vector<int>> quadruplets;
 * 
 *     // Sort nums
 *     sort(nums.begin(), nums.end());
 * 
 *     // Loop invariant is a < b < c < d (note strictness)
 *     for (int a = 0; a < n - 3; ++a) {
 *       // Skip duplicates of outer loop
 *       if (a > 0 && nums[a] == nums[a - 1]) continue;
 * 
 *       // 3Sum with target = target - nums[a]
 *       int t = target - nums[a];
 *       for (int b = a + 1; b < n - 2; ++b) {
 *         // Skip duplicates
 *         if (b > a + 1 && nums[b] == nums[b - 1]) continue;
 * 
 *         int c = b + 1, d = n - 1;
 *         while (c < d) {
 *           int sum = nums[b] + nums[c] + nums[d];
 *           if (sum == t) {
 *             quadruplets.push_back({nums[a], nums[b], nums[c], nums[d]});
 *             while (c < d && nums[c] == nums[++c]) continue;
 *             while (c < d && nums[d] == nums[--d]) continue;
 *           } else if (sum < t) {
 *             ++c;
 *           } else if (sum > t) {
 *             --d;
 *           }
 *         }
 *       }
 *     }
 *     return quadruplets;
 *   }
 * };
 */

/**
 *  Two Pointer
 *
 *  Three Sum for all nums[i..n) where i = [1..n - 3) with 
 *  target = target - nums[i]
 *
 *  Time: O(n^3)
 *  Space: O(1)
 */
class Solution {
 private:
  vector<vector<int>> threeSum(vector<int>& nums, int start, int end, int target) {
    vector<vector<int>> res;
    for (int i = start; i < nums.size() - 2; ++i) {
      // Skip duplicates
      if (i > start && nums[i] == nums[i - 1]) continue;

      int low = i + 1, high = end;
      while (low < high) {
        int sum = nums[i] + nums[low] + nums[high];
        if (sum == target) {
          res.push_back({nums[i], nums[low], nums[high]});
          while (low < high && nums[low] == nums[++low]) continue;
          while (low < high && nums[high] == nums[--high]) continue;
        } else if (sum < target) {
          ++low;
        } else if (sum > target) {
          --high;
        }
      }
    }
    return res;
  }

 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) return {};
    int n = nums.size();
    vector<vector<int>> res;

    // Sort nums
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; ++i) {
      // Skip duplicates of outer loop
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      vector<vector<int>> tmp = threeSum(nums, i + 1, n - 1, target - nums[i]);
      for (auto& s : tmp) {
        s.push_back(nums[i]);
        res.push_back(std::move(s));
      }
    }
    return res;
  }
};
