/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (49.22%)
 * Total Accepted:    153.9K
 * Total Submissions: 311.9K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 *
 *
 * Note:
 *
 *
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 *
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Hash Set
 *
 *  Store nums2 in hash set and then iterate through nums1
 *
 *  Time: O(N1 + N2)
 *  Space: O(N2)
 */
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0 || nums2.size() == 0) return {};

    // Remove duplicate elements and change look-up to O(1)
    unordered_set<int> s(nums2.begin(), nums2.end());

    unordered_set<int> intersects;
    for (const auto& n : nums1) {
      if (s.find(n) != s.end()) {
        intersects.insert(n);
      }
    }

    return vector<int>(intersects.begin(), intersects.end());
  }
};
