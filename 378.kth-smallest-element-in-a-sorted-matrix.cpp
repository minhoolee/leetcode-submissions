/*
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (46.10%)
 * Total Accepted:    71.9K
 * Total Submissions: 156K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 *
 *
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 *
 *
 * Example:
 *
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 *
 * return 13.
 *
 *
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Test cases
 *
 *  [] => -1?
 *  Ex., k = 8 => 13
 *  [1], k = 1 => 1
 */

/**
 *  Min Heap / k-way Merge
 *
 *  Add right or bottom to min heap
 *
 *  Time: O(klogn)
 *  Space: O(k), worst case O(n^2)
 */
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return -1;
    int m = matrix.size(), n = matrix[0].size();

    auto comp = [&](const auto& a, const auto& b) {
      return matrix[a[0]][a[1]] > matrix[b[0]][b[1]];
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
    pq.push({0, 0});

    for (int j = 1; j < n; ++j) pq.push({0, j});

    auto curr = pq.top();

    for (int i = 0; i < min(m * n, k); ++i) {
      curr = pq.top();
      pq.pop();
      if (curr[0] + 1 < m) pq.push({curr[0] + 1, curr[1]});
    }

    return matrix[curr[0]][curr[1]];
  }
};
