/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.92%)
 * Total Accepted:    358.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
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
 *  Brute force approach
 *
 *  Iterate over all possible subsets of triplets and check if sum is 0
 *
 *  Time: O(n^3)
 *  Space: O(1)
 */

/**
 *  Hash table approach
 *
 *  Hash table single pass like 1.two-sum but instead of a + b = 0 use
 *  a + b = -c, where a and b != c and c iterates through all nums
 *
 *  Time: O(n^2)
 *  Space: O(n)
 */

/**
 *  Comparison Two Sum approach
 *
 *  Start at ends of array and increment low and decrement high depending
 *  on whether sum >, <, or = 0
 *
 *  Time: O(n^2)
 *  Space: O(1)
 *
 *  threeSum(nums):
 *    init triplets as empty dynamic array of dynamic arrays
 *    sort nums
 *    set n to nums' length
 *
 *    // a iterates from 0 to third to last element
 *    for i in [0..n-3]
 *      // Array is sorted so b + c cannot be negative if a is positive
 *      if nums[i] > 0
 *        break loop
 *
 *      // Check that i is not duplicate
 *      if i does not equal 0 and nums[i] == nums[i-1]
 *        continue loop
 *
 *      set low to i+1, high to n-1
 *
 *      while low < high
 *        set sum to nums[low] + nums[high] + nums[i]
 *        if sum equals 0
 *          add {nums[i], nums[low], nums[high]} to triplets
 *          // Skip duplicates or break loop if no more unique low and high
 *          while low < high and nums[low] equals nums[low+1]
 *            increment low
 *          while low < high and nums[high] equals nums[high-1]
 *            decrement high
 *          increment low
 *          decrement high
 *        else if sum > 0
 *          decrement high
 *        else if sum < 0
 *          increment low
 *    return triplets
 */
class Solution {
 public:
  vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > triplets;
    std::sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; ++i) {
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int low = i + 1, high = n - 1;

      while (low < high) {
        long sum = nums[low] + nums[high] + nums[i];
        if (sum == 0) {
          triplets.push_back(vector<int>{nums[i], nums[low], nums[high]});
          while (low < high && nums[low] == nums[++low]) continue;
          while (low < high && nums[high] == nums[--high]) continue;
        } else if (sum > 0) {
          --high;
        } else if (sum < 0) {
          ++low;
        }
      }
    }

    return triplets;
  }
};
