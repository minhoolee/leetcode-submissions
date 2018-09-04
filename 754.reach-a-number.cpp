/*
 * [755] Reach a Number
 *
 * https://leetcode.com/problems/reach-a-number/description/
 *
 * algorithms
 * Medium (28.80%)
 * Total Accepted:    4.8K
 * Total Submissions: 16.8K
 * Testcase Example:  '1'
 *
 *
 * You are standing at position 0 on an infinite number line.  There is a goal
 * at position target.
 *
 * On each move, you can either go left or right.  During the n-th move
 * (starting from 1), you take n steps.
 *
 * Return the minimum number of steps required to reach the destination.
 *
 *
 * Example 1:
 *
 * Input: target = 3
 * Output: 2
 * Explanation:
 * On the first move we step from 0 to 1.
 * On the second step we step from 1 to 3.
 *
 *
 *
 * Example 2:
 *
 * Input: target = 2
 * Output: 3
 * Explanation:
 * On the first move we step from 0 to 1.
 * On the second move we step  from 1 to -1.
 * On the third move we step from -1 to 2.
 *
 *
 *
 * Note:
 * target will be a non-zero integer in the range [-10^9, 10^9].
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
 *  It took me too long to realize that recursive, tab, and memo won't work.
 *  The main issue is that bounds of target is 10^9 which is far to big to
 *  store in memory (O(n)) or process (O(2^n)).
 *
 *  Frankly speaking, I'm still not sure how I would come up with this
 *  solution ad hoc. Maybe just run through a ton of cases and simplify
 *  the format of intermediate steps (e.g. don't use graph to represent
 *  values but instead show S = {1, 2, 3 .. k} in one line
 *
 *  I need more practice with math problems.
 */
/**
 *  Greedy
 *
 *  Key observations:
 *  Use abs(target) because the tree is mirrored about horizontal axis (for 0)
 *  If overshoot from target is even, you can always reverse previous moves.
 *
 *  let T = target
 *  let S = {1, 2, ..., k}
 *  S >= T
 *  let res = S - T (overshoot)
 *  if S = T:
 *    return k
 *  if res is even, S - res can be reached by reversing sign of values in S:
 *    return k
 *  if res is odd:
 *    if k + 1 is odd:
 *      res + (k + 1) is even, so return k + 1 (see res is even)
 *    if k + 1 is even:
 *      res + (k + 1) + (k + 2) is even, so return k + 2 (see res is even)
 *
 *  We can optimize the greedy solution even further by calculating k using
 *  the quadratic formula
 *
 *  1 + 2 + .. + k - 1 + k >= T
 *  (k)(k + 1)/2 >= T
 *  1/2 * k^2 + 1/2 * k - T >= 0
 *  k >= -1/2 +- sqrt(1/4 + 2T)
 *
 *  I'm not sure how to prove that res is even works or that res is odd results
 *  in minimum number of steps.
 *
 *  Time: O(sqrt(n))
 *  Space: O(1)
 */
class Solution {
 private:
  bool is_even(int x) { return (x & 1) == 0; }

 public:
  int reachNumber(int target) {
    target = abs(target);

    // S = 1 + 2 + .. + k >= target
    long long k = ceil(-1.0 / 2 + sqrt(1.0 / 4 + 2 * target));
    long long sum = (k) * (k + 1) / 2;
    long long res = sum - target;

    if (res == 0)
      return k;
    else if (is_even(res))
      return k;
    else
      return !is_even(k + 1) ? k + 1 : k + 2;
  }
};
