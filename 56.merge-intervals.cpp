/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (32.71%)
 * Total Accepted:    224.9K
 * Total Submissions: 686.8K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 *
 *
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
 *
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Sliding window approach
 *
 *  Slide window while intervals overlap and then merge and reset window
 *
 *  Time: O(n)
 *  Space: O(n)
 *
 *  merge(intervals):
 *    set min to intervals[0].start
 *    set max to intervals[0].end
 *    set mergedIntervals to empty list of Intervals
 *
 *    for i in [1..intervals.size]
 *      set windowInterval to Interval(min, max)
 *
 *      if not isOverlapping(windowInterval, intervals[i]) ||
 *        i = intervals.size:
 *
 *        add windowInterval to mergedIntervals
 *        set min to intervals[i].start
 *        set max to intervals[i].end
 *      else
 *        set min to min(min, intervals[i].start)
 *        set max to max(max, intervals[i].end)
 *
 *    return mergedIntervals
 *
 *  isOverlapping(a, b):
 *    return b.start <= a.end and a.start <= b.end
 *
 *  merge(a, b):
 *    return Interval(min(a.start, b.start), max(a.end, b.end))
 */
/**
 *  Test cases
 *
 *  [[2,6],[1,3]] => [[1,6]]
 *  [[2,6],[1,3],[5,8]] => [[1,8]]
 *  [[2,9],[1,3],[5,8]] => [[1,9]]
 *  [[2,3],[4,5],[1,6]] => [[1,6]]
 */
class Solution {
 private:
  bool isOverlapping(Interval& a, Interval& b) {
    return b.start <= a.end and a.start <= b.end;
  }

  static bool compare(Interval& a, Interval& b) { return a.start < b.start; }

 public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) return vector<Interval>();
    sort(intervals.begin(), intervals.end(), compare);

    int min = intervals[0].start;
    int max = intervals[0].end;
    vector<Interval> mergedIntervals;

    for (int i = 1; i <= intervals.size(); ++i) {
      Interval windowInterval = Interval(min, max);

      if (!isOverlapping(windowInterval, intervals[i]) ||
          i == intervals.size()) {
        mergedIntervals.push_back(windowInterval);
        min = intervals[i].start;
        max = intervals[i].end;
      } else {
        min = std::min(min, intervals[i].start);
        max = std::max(max, intervals[i].end);
      }
    }

    return mergedIntervals;
  }
};
