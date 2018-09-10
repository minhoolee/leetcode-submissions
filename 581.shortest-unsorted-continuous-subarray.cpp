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
 *  Notes for improvement
 *
 *  Figure out better names than low and high (not same # of letters). I don't
 *  like lo and hi, but single letter names like l, h and l, r arent great.
 *
 *  I originally misinterpreted this problem, I thought it was just simple two
 *  pointer but the key is that max and min of unsorted array are not i and j,
 *  respectively. The insertion points are the actual i and j, and figuring
 *  those out in an efficient, clean manner for this problem is surprisingly
 *  difficult (most solutions require multiple loops).
 */

/**
 *  Two Pointer
 *
 *  Find min and max of unsorted array and determine where they should be
 *  inserted
 *
 *  let unsorted array = arr[i:j]
 *  Max needs to be inserted at j = min(arr[j + 1 : n - 1])
 *  Min needs to be inserted at i = max(arr[0 : i - 1])
 *
 *  Easiest way to come to this method is:
 *  1) Pretend you somehow have max(arr[i:j]). The location it needs to be
 *     inserted is when nums[k] > max(arr[i:j])
 *  2) Pretend you somehow have min(arr[i:j]). The location it needs to be
 *     inserted is when nums[k] < min(arr[i:j])
 *
 *  1) Find first local max and then find next nums[i] > local max
 *    Keep updating max, low++
 *    if nums[low] != max (no longer sorted):
 *      j := low
 *
 *  max and min of arr[i:j] is irrelevant, only i and j (insertion points)
 *  matter
 *
 *  Time: O(n)
 *  Space: O(1)
 */
/**
 * class Solution {
 *  public:
 *   int findUnsortedSubarray(vector<int>& nums) {
 *     if (nums.empty()) return 0;
 *
 *     int i = 0, j = -1;
 *     int min = INT_MAX, max = INT_MIN;
 *
 *     for (int l = 0, r = nums.size() - 1; r >= 0; ++l, --r) {
 *       max = std::max(max, nums[l]);
 *       if (nums[l] != max) j = l;
 *
 *       min = std::min(min, nums[r]);
 *       if (nums[r] != min) i = r;
 *     }
 *
 *     return (j - i + 1);
 *   }
 * };
 */
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0, j = -1;
    int min = INT_MAX, max = INT_MIN;

    for (int l = 0; l < nums.size(); ++l) {
      max = std::max(max, nums[l]);
      if (nums[l] != max) j = l;
    }

    for (int r = nums.size() - 1; r >= 0; --r) {
      min = std::min(min, nums[r]);
      if (nums[r] != min) i = r;
    }

    return (j - i + 1);
  }
};
