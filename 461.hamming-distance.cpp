/*
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (69.55%)
 * Total Accepted:    180.6K
 * Total Submissions: 259.7K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 ≤ x, y < 231.
 *
 *
 * Example:
 *
 * Input: x = 1, y = 4
 *
 * Output: 2
 *
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 *
 * The above arrows point to positions where the corresponding bits are
 * different.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Test cases
 *
 *  x = 1, y = 3 => 1
 *  x = 1, y = 1 => 0
 *  x = 0, y = 0 => 0
 */

/**
 *  Bit Manipulation
 *
 *  For k in [0..log(max(x, y))] check if x >> k = y >> k
 *
 *  Time: O(log(max(x, y))
 *  Space: O(1)
 */
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int h_dist = 0;
    int bits = (int)log2(max(x, y));

    for (int k = 0; k <= bits; ++k) {
      // Check equality of kth bit of x and y
      if (((x >> k) & 1) != ((y >> k) & 1)) {
        ++h_dist;
      }
    }
    return h_dist;
  }
};
