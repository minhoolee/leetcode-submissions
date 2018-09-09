/*
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.33%)
 * Total Accepted:    44.1K
 * Total Submissions: 150.6K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 *
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 *
 *
 *
 * Note:
 *
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means .
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Two Pointer
 *
 *  Time: O(n)
 *  Space: O(1)
 */
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0, j = -1;
    int min = INT_MAX, max = INT_MIN;

    for (int low = 0, high = nums.size() - 1; high >= 0; ++low, --high) {
      max = std::max(max, nums[low]);
      if (nums[low] != max) j = low;

      min = std::min(min, nums[high]);
      if (nums[high] != min) i = high;
    }

    return (j - i + 1);
  }
};
