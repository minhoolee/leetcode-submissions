/*
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (31.73%)
 * Total Accepted:    47K
 * Total Submissions: 148.1K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 *
 *
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 *
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 *
 *
 * Example 1:
 *
 * Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 *
 * Return: [1,2],[1,4],[1,6]
 *
 * The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 *
 *
 *
 * Example 2:
 *
 * Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 *
 * Return: [1,1],[1,1]
 *
 * The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 *
 *
 *
 * Example 3:
 *
 * Given nums1 = [1,2], nums2 = [3],  k = 3
 *
 * Return: [1,3],[2,3]
 *
 * All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 *
 *
 *
 * Credits:Special thanks to @elmirap and @StefanPochmann for adding this
 * problem and creating all test cases.
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Notes for improvement
 *
 *  This may be the ugliest solution I have submitted. I am ashamed.
 *  Note to self: never use tuples/pairs. I am so disappointed.
 *  This problem is pretty interesting, however, so I'll reimplement it
 *
 *  EDIT: See earlier submission for use of pairs and get<i>()
 */

/**
 *  Priority Queue / Min Heap / k-way Merge
 *
 *  Add all pairs in {num1, 0} to pq and then determine whether to add
 *  {after(num1), num2} or {num1, after(num2)}
 *
 *  Time: O(klogk)
 *  Space: O(k)
 */
class Solution {
 public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                        int k) {
    vector<pair<int, int>> ans;

    int N1 = nums1.size(), N2 = nums2.size();
    if (N1 == 0 || N2 == 0) return ans;

    // Wow this sucks...
    auto comp_pair = [&](const auto& a, const auto& b) {
      return (nums1[a[0]] + nums2[a[1]]) > (nums1[b[0]] + nums2[b[1]]);
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(comp_pair)> pq(
        comp_pair);

    // Add all indices from i, each paired with first element of nums2
    for (int i = 0; i < min(N1, k); ++i) pq.push({i, 0});

    while (k-- > 0 && !pq.empty()) {
      const auto curr = pq.top();
      pq.pop();
      ans.push_back(make_pair(nums1[curr[0]], nums2[curr[1]]));

      // Add {num1, after(num2)}, which may be before or after
      // {after(num1), num2}
      if (curr[1] + 1 < N2) {
        pq.push({curr[0], curr[1] + 1});
      }
    }

    return ans;
  }
};
