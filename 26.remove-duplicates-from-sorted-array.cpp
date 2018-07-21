/*
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (37.18%)
 * Total Accepted:    387.1K
 * Total Submissions: 1M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */

static auto x = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return nullptr;
}();

class Solution {
 public:
  // Use two pointers, one slow one fast, to go through loop once
  // Time: O(n)
  // Space: O(1)
  int removeDuplicates(vector<int>& nums) {
    // Return 0 if empty array
    if (nums.size() == 0) return 0;

    // Set i (slow) to 0 and j (fast) to 1
    int i = 0;

    // Loop through nums until j hits end
    for (int j = 1; j < nums.size(); ++j) {
      // If nums[i] != nums[j], increment i and set nums[i] to nums[j
      if (nums[i] != nums[j]) {
        nums[++i] = nums[j];
      }
    }

    // return slow + 1
    return i + 1;
  }
};
