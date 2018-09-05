/*
 * [454] 4Sum II
 *
 * https://leetcode.com/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (48.08%)
 * Total Accepted:    42.2K
 * Total Submissions: 87.6K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * Given four lists A, B, C, D of integer values, compute how many tuples (i,
 * j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 *
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤
 * N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is
 * guaranteed to be at most 231 - 1.
 *
 * Example:
 *
 * Input:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
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
 *  This problem relies very heavily on going from brute force to optimal
 *  approach. Thus, it is imperative that I consider brute force first
 *  (and understand its time and space complexities).
 *
 *  From the brute force 4 for loops, I should then go to 3 for loops + hash +
 *  1 for loop, and then 2 for loops + hash + 2 for loops
 *  AKA: 4 -> 3 + 1 -> 2 + 2
 */

/**
 *  Brute Force
 *
 *  4 nested for loops through A then B then C then D and finally check
 *  if a + b + c + d = 0
 *
 *  Time: O(n^4)
 *  Space: O(1)
 */

/**
 *  Hash Map
 *
 *  2 nested for loops through A then B, count freq of a + b sum
 *  Then, 2 nested for loops through C and D, search map of -(c + d) sum freq
 *
 *  Time: O(n^2)
 *  Space: O(n^2)
 */
class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {
    unordered_map<int, int> sums;
    int res = 0;

    for (int a : A) {
      for (int b : B) {
        ++sums[a + b];
      }
    }

    for (int c : C) {
      for (int d : D) {
        res += sums[-(c + d)];
      }
    }

    return res;
  }
};
