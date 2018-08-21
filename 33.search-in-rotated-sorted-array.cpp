/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.02%)
 * Total Accepted:    287.8K
 * Total Submissions: 898.4K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
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
 *  a + (b - a) / 2 is better than (a + b) >> 1 because ">>" is signed bit
 *  shift, which will cause a bug with negative a and b. In Java this can be
 *  fixed with the unsigned bit shift ">>>" but this is not available in C++.
 */

/**
 *  Modified binary search approach
 *
 *  Use low, high, mid but determine which side has split
 *
 *  Time: O(logn)
 *  Space: O(1)
 *
 *  search(nums, target):
 *    set low to 0, high to nums.size - 1
 *    while low <= high:
 *      mid = (low + high) / 2
 *      if nums[mid] = target:
 *        return mid
 *
 *      // Left of mid does not have split
 *      if nums[low] < nums[mid]:
 *        if nums[low] <= target < nums[mid]:
 *          set high to mid - 1
 *        else:
 *          set low to mid + 1
 *      // Left of mid has split
 *      else:
 *        if nums[mid] < target <= nums[high]:
 *          set low to mid + 1
 *        else:
 *          set high to mid - 1
 *
 *    return -1
 */
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) return mid;

      if (nums[low] <= nums[mid]) {
        if (nums[low] <= target && target < nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return -1;
  }
};
