/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (37.72%)
 * Total Accepted:    222.1K
 * Total Submissions: 588.8K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 *
 *
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49.
 *
 *
 *
 * Example:
 *
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
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
 *  Find maximum area of all possible subsets
 *
 *  Time: O(n^2)
 *  Space: O(1)
 */

/**
 *  Optimal approach (two pointer)
 *
 *  Fast pointer has shorter line length and moves towards slow pointer
 *
 *  Time: O(n)
 *  Space: O(1)
 *
 *  maxArea(height):
 *    set l to 0
 *    set r to n-1
 *    set maxA to 0
 *
 *    while l < r
 *      set maxA to max(maxA, min(height[l], height[r]) * (r-l))
 *
 *      // Pointer to shorter line moves towards other pointer
 *      // in order to change area and possibly max area
 *      if height[l] < height[r]
 *        increment l
 *      else
 *        decrement r
 *    return maxA
 */

/**
 *  Test cases
 *
 *  [1,8,2,50,50,2,8,1] => 50
 *  [1,1] => 1
 *  [1,1,1,1,1,50,50] => 50
 */
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int maxA = 0;

    while (l < r) {
      maxA = max(maxA, min(height[l], height[r]) * (r - l));
      if (height[l] < height[r])
        ++l;
      else
        --r;
    }

    return maxA;
  }
};
