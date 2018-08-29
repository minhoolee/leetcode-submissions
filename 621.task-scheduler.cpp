/*
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (42.67%)
 * Total Accepted:    45.1K
 * Total Submissions: 105.6K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks.Tasks could
 * be done without original order. Each task could be done in one interval. For
 * each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 *
 * Example 1:
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 *
 *
 *
 * Note:
 *
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
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
 *  This problem is similar to converting list to matrix. See how numpy
 *  arrays are implemented to understand 1D -> 2D.
 */

/**
 *  Test cases
 *
 *  empty => 0
 *  [A], n = 100 => 1
 *  [A, A], n = 0 => 2
 *  [A, A], n = 100 => 102
 *  [B, A, A], n = 1 => 3
 */

/**
 *  Hash table
 *
 *  Build frequency map, set width to highest freq * n, and add surplus
 *
 *  Time: O(n)
 *  Space: O(1) or O(k) where k = num of distinct characters <= 26
 */

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    if (tasks.empty()) return 0;

    // Build freq table
    map<char, int> freq;
    for (const auto& task : tasks) {
      ++freq[task];
    }

    // Find max freq
    int max_freq = INT_MIN;
    for (const auto& f : freq) {
      max_freq = max(max_freq, f.second);
    }

    // Excluding last => max_freq blocks spaced n + 1 apart
    int num_intervals = (max_freq - 1) * (n + 1);

    // Add additional tasks that have max freq
    for (const auto& f : freq) {
      if (f.second == max_freq) {
        ++num_intervals;
      }
    }

    // Everything goes out the window if more tasks than blocks
    return max((int)tasks.size(), num_intervals);
  }
};

/**
 *  Priority Queue + Map
 *
 *  Greedily select max freq at each time step (interval)
 *
 *  Make priority queue of frequencies (descending) and for each interval,
 *  pull from priority queue (until its freq = 0) and save in map at
 *  time t + n + 1.
 *
 *  Time: O(n)
 *  Space: O(n)
 */
