/*
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (45.44%)
 * Total Accepted:    123.3K
 * Total Submissions: 271.3K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Example 1:
 *
 *
 * Input: [1,3,4,2,2]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [3,1,3,4,2]
 * Output: 3
 *
 * Note:
 *
 *
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Proof is pigeon hole principle
 *  n + 1 elements and n values -> one duplicate
 */

/**
 *  Brute force approach (too slow)
 *
 *  Nested for loops
 *
 *  Time: O(n^2)
 *  Space: O(1)
 */

/**
 *  Sort approach (invalid)
 *
 *  Sort using heap sort and traverse element for duplicate
 *
 *  On second thought, this approach is invalid because it modifies the array
 *
 *  Time: O(nlogn)
 *  Space: O(1)
 */

/**
 *  Floyd Cycle approach
 *
 *  Floyd Cycle array treating each val as node whose next node is index val
 *
 *  Note that the cyclic linked list may not contain all n + 1 elements.
 *  n + 1 indexes and n elements implies the array can be traversed infinitely
 *  therefore, there must be a cycle! Cycle start detection can be done with
 *  the two stage floyd cycle (tortoise and hare) approach. Finding start of
 *  cycle is same as finding duplicate.
 *
 *  Time: O(n)
 *  Space: O(1)
 *
 *  findDuplicate(nums):
 *    set slow, fast to nums[0]
 *    do
 *      set slow to nums[slow]
 *      set fast to nums[nums[fast]]
 *    while slow != fast
 *
 *    // Reset slow to head in order to find cycle start
 *    set slow to nums[0]
 *    while slow != fast
 *      set slow to nums[slow]
 *      set fast to nums[fast]
 *
 *    return slow
 */
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Detect cycle
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    // Find cycle start
    slow = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};
