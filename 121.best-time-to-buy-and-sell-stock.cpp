/*
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (43.68%)
 * Total Accepted:    322.5K
 * Total Submissions: 736.6K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 *
 * Note that you cannot sell a stock before you buy one.
 *
 * Example 1:
 *
 *
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 *
 * Example 2:
 *
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  First approach
 *
 *  Calculate profit for each day, in place, and find max profit
 *
 *  Time: O(n^2)
 *  Space: O(1)
 */

/**
 *  Better approach
 *
 *  Global min and local max versus local min and global max
 *
 *  Time: O(n)
 *  Space: O(1)
 */

/**
 *  Optimal approach
 *
 *  One pass, update local min and local max for highest profit
 *
 *  Time: O(n)
 *  Space: O(1)
 *
 *  maxProfit(prices):
 *    Set min to prices[0]
 *    Set maxProfit to 0
 *    For i in prices
 *      If prices[i] < min
 *        Set min to prices[i]
 *      Else if prices[i] - min > maxProfit
 *        Set maxProfit to prices[i] - min
 *
 *    Return maxProfit
 */

/**
 *  Test cases
 *
 *  [1,2,3,4,5] => 4
 *  [2,8,1,4] => 6
 *  [0,0,0] => 0
 *  [] => 0
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int min = prices[0];
    int maxProfit = 0;

    for (int price : prices) {
      if (price < min)
        min = price;
      else if (price - min > maxProfit)
        maxProfit = price - min;
    }

    return maxProfit;
  }
};
