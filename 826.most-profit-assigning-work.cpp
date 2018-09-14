/*
 * [826] Most Profit Assigning Work
 *
 * https://leetcode.com/problems/most-profit-assigning-work/description/
 *
 * algorithms
 * Medium (32.78%)
 * Total Accepted:    5.3K
 * Total Submissions: 16.2K
 * Testcase Example:  '[2,4,6,8,10]\n[10,20,30,40,50]\n[4,5,6,7]'
 *
 * We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i]
 * is the profit of the ith job. 
 *
 * Now we have some workers. worker[i] is the ability of the ith worker, which
 * means that this worker can only complete a job with difficulty at most
 * worker[i]. 
 *
 * Every worker can be assigned at most one job, but one job can be completed
 * multiple times.
 *
 * For example, if 3 people attempt the same job that pays $1, then the total
 * profit will be $3.  If a worker cannot complete any job, his profit is $0.
 *
 * What is the most profit we can make?
 *
 * Example 1:
 *
 *
 * Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker =
 * [4,5,6,7]
 * Output: 100
 * Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get
 * profit of [20,20,30,30] seperately.
 *
 * Notes:
 *
 *
 * 1 <= difficulty.length = profit.length <= 10000
 * 1 <= worker.length <= 10000
 * difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Sort
 *
 *  Sort jobs and workers and keep track of highest profit jobs that can be
 *  done
 *
 *  Time: O(nlogn)
 *  Space: O(n)
 */
class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                          vector<int>& worker) {
    int n = difficulty.size();
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; ++i) {
      jobs.push_back(std::make_pair(difficulty[i], profit[i]));
    }

    std::sort(jobs.begin(), jobs.end());
    std::sort(worker.begin(), worker.end());

    int i = 0;
    int best_profit = 0;
    int total_profit = 0;
    for (const auto& ability : worker) {
      // Of all jobs that can be done, choose highest paying
      while (i < n && ability >= jobs[i].first) {
        best_profit = std::max(best_profit, jobs[i].second);
        ++i;
      }
      total_profit += best_profit;
    }
    return total_profit;
  }
};
