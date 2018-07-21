/*
 * [27] Remove Element
 *
 * https://leetcode.com/problems/remove-element/description/
 *
 * algorithms
 * Easy (41.46%)
 * Total Accepted:    297K
 * Total Submissions: 716K
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an array nums and a value val, remove all instances of that value
 * in-place and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [3,2,2,3], val = 3,
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 2.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,1,2,2,3,0,4,2], val = 2,
 * 
 * Your function should return length = 5, with the first five elements of nums
 * containing 0, 1, 3, 0, and 4.
 * 
 * Note that the order of those five elements can be arbitrary.
 * 
 * It doesn't matter what values are set beyond the returned length.
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
 * int len = removeElement(nums, val);
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
  // Two pointer approach, swap slow and fast when slow is val and fast isn't
  // Time: O(n)
  // Space: O(1)
  //
  // Test cases:
  // [3,3],3 -> []
  // [3,3],2 -> [3,3]
  // [] -> []
  // [0,2,2],2 -> [0]
  //
  // Return 0 if nums is empty
  // Set i (slow) to 0 and j (fast) to length (not length-1 because
  // j = length when val is not present
  // Loop until i >= j
    // If nums[i] != val, increment i
    // Else
      // Set nums[i] to nums[j-1]
      // Decrement j
  // Return i
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) return 0;
    int i = 0, j = nums.size();

    while (i < j) {
      if (nums[i] != val) {
        ++i;
      } else {
        nums[i] = nums[j-1];
        --j;
      }
    }
    return j;
  }
};
