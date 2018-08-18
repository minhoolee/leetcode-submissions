/*
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (29.53%)
 * Total Accepted:    137.8K
 * Total Submissions: 466.5K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 * start times.
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
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
 *  Brute force approach
 *
 *  Either merge or add interval to new list
 *
 *  Time: O(n^2)
 *  Space: O(1)
 */

/**
 *  Sorting approach
 *
 *  Insert new interval into its correct position by binary search and
 *  merge intervals
 *
 *  Time: O(n)
 *  Space: O(1)
 *
 *  insert(intervals, newInterval):
 *    if intervals is empty return new list containing newInterval
 *
 *    init res to copy of intervals
 *
 *    set i to binarySearch(res, newInterval.start, 0, intervals.size - 1)
 *    insert newInterval to res[i]
 *
 *    res = mergeIntervals(res)
 *
 *    return res
 *
 *  binarySearch(intervals, val, low, high):
 *    if low > high
 *      return low
 *
 *    set mid to (low + high) / 2
 *
 *    if intervals[mid].start > val
 *      return binarySearch(intervals, val, low, mid - 1)
 *    else if intervals[mid].start < val
 *      return binarySearch(intervals, val, mid + 1, high)
 *    else
 *      return mid
 *
 *  mergeIntervals(intervals):
 *    init res to empty list of intervals
 *
 *    for int in intervals
 *      if res is not empty and int.start <= end
 *        set res.back.end to max(res.back.end, int.end)
 *      // Interval and merged interval doesn't overlap
 *      else
 *        add int to res
 *
 *    return res
 *
 */
class Solution {
 private:
  int binarySearch(vector<Interval>& intervals, int val, int low, int high) {
    if (low > high) return low;

    int mid = (low + high) >> 1;

    if (intervals[mid].start > val)
      return binarySearch(intervals, val, low, mid - 1);
    else if (intervals[mid].start < val)
      return binarySearch(intervals, val, mid + 1, high);
    else
      return mid;
  }

  vector<Interval> mergeIntervals(vector<Interval>& intervals) {
    vector<Interval> res;

    for (Interval& interval : intervals) {
      if (!res.empty() && interval.start <= res.back().end)
        res.back().end = max(res.back().end, interval.end);
      else
        res.push_back(interval);
    }

    return res;
  }

 public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    if (intervals.empty()) return vector<Interval>(1, newInterval);

    vector<Interval> res = intervals;

    int i = binarySearch(intervals, newInterval.start, 0, intervals.size() - 1);
    res.insert(res.begin() + i, newInterval);

    res = mergeIntervals(res);

    return res;
  }
};
