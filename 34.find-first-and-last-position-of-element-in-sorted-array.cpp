/*
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (31.90%)
 * Total Accepted:    212.6K
 * Total Submissions: 665.9K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
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
 *  Better solution is binary search for low and high separately.
 *  Note: will need to check BS return value to see if target exists
 *
 *  BS for low requires continuing binary search (to left) if A[mid] = target
 *  and return low instead of mid. This works because it effectively
 *  binary searches for low once you hit a value inside interval [low, high].
 *
 *  BS for high uses BS for target + 1. This works because BS will return
 *  insertion position for value even if it does not exist.
 */

/**
 *  Binary search approach
 *
 *  Binary search for target and then expand window both directions
 *
 *  Time: O(logn + k), where k is size of target interval
 *        Degrades to O(n) when all elements are target
 *  Space: O(1)
 *
 *  searchRange(nums, target):
 *    set low to binarySearch(nums, target)
 *    set high to low
 *
 *    if low = -1:
 *      return -1 and -1
 *
 *    while low > 0 and nums[low - 1] = nums[low]:
 *      decrement low
 *    while high < nums.size and nums[high + 1] = nums[high]:
 *      increment high
 *
 *    return low and high
 *
 *  binarySearch(nums, target):
 *    set low to 0, high to nums.size - 1
 *
 *    while low <= high:
 *      set mid to (low + high) / 2
 *      if nums[mid] = target:
 *        return mid
 *      if target > nums[mid]:
 *        set low to mid + 1
 *      else if target < nums[mid]:
 *        set high to mid - 1
 *
 *    return -1
 */

/**
 *  Test cases
 *
 *  [1,2,3,4,4,4,4]; 4 => [3,6]
 *  [1,2,3,4,5,6,7]; 1 => [0,0]
 *  [1,1,1,1,1,1,2]; 2 => [6,6]
 *  [1,1,1,1,1,1,1]; 1 => [0,6]
 *  []; 1 => [-1,-1]
 */
class Solution {
 private:
  int binarySearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target)
        return mid;
      else if (target > nums[mid])
        low = mid + 1;
      else if (target < nums[mid])
        high = mid - 1;
    }

    return -1;
  }

 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int low = binarySearch(nums, target);
    int high = low;

    if (low == -1) return {-1, -1};

    while (low > 0 && nums[low - 1] == nums[low]) --low;
    while (high < nums.size() - 1 && nums[high + 1] == nums[high]) ++high;

    return {low, high};
  }
};
