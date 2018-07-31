/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.03%)
 * Total Accepted:    280.5K
 * Total Submissions: 700.5K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5,6], 5
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [1,3,5,6], 2
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: [1,3,5,6], 7
 * Output: 4
 *
 *
 * Example 4:
 *
 *
 * Input: [1,3,5,6], 0
 * Output: 0
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  First approach
 *
 *  Loop until value is greater or equal to target
 *
 *  Time: O(n)
 *  Space: O(1)
 */

/**
 *  Optimal approach
 *
 *  Binary search
 *
 *  Time: O(logn)
 *  Space: O(1)
 *
 *  search(nums, low, high, target):
 *    Set mid to (low + high) / 2
 *    If nums[mid] equals target, return mid
 *
 *    // Low passes high when target is not found
 *    If low > high, return low
 *
 *    If nums[mid] > target
 *      Return search(nums, low, mid-1, target)
 *    Else
 *      Return search(nums, mid+1, high, target)
 *
 *  searchInsert(nums, target):
 *    Set low to 0 and high to nums' length-1
 *    Return search(nums, target)
 */

/**
 *  Test cases
 *
 *  [-3,-2,-1], 0 => 3
 */
class Solution {
 private:
  int search(std::vector<int>& nums, int low, int high, int target) {
    int mid = (low + high) / 2;
    if (nums[mid] == target) return mid;

    // Low passes high when target is not found
    if (low > high) return low;

    if (nums[mid] > target)
      return search(nums, low, mid - 1, target);
    else
      return search(nums, mid + 1, high, target);
  }

 public:
  int searchInsert(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    return search(nums, low, high, target);
  }
};
