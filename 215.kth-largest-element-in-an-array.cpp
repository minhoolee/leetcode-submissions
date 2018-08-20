/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (42.22%)
 * Total Accepted:    241.1K
 * Total Submissions: 570.6K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
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
 *  Get max element k times
 *
 *  Time: O(nk)
 *  Space: O(1) or O(n) if immutable
 */

/**
 *  Sort approach
 *
 *  Sort and return kth last element
 *
 *  Time: O(nlogn)
 *  Space: O(1) or O(n) if immutable
 */

/**
 *  Max heap approach
 *
 *  Max heapify nums and return kth max
 *
 *  Time: O(klogn)
 *  Space: O(1) or O(n) if immutable
 *
 *  findKthLargest(nums, k):
 *    max heapify nums to turn nums into a max heap (property is fullfilled)
 *    for i in [0..k - 1):
 *      delete nums.max (making sure property is maintained)
 *    return nums.max
 */
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    std::make_heap(nums.begin(), nums.end());

    for (int i = 0; i < k - 1; ++i) {
      std::pop_heap(nums.begin(), nums.end());
      nums.pop_back();
    }

    return nums.front();
  }
};
