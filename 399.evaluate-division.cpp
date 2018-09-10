/*
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (43.10%)
 * Total Accepted:    40K
 * Total Submissions: 92.7K
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[
 * ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 *
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 *
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 *
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 *
 *
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ].
 *
 *
 *
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
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
 *  I first attacked this problem by walking through a test case, noticing a
 *  pattern and then jumping to DP. Something to keep in mind is that DP is
 *  actually pretty slow; for some problems it may be optimal but for other
 *  problems there may be better solutions. In other words, a DP solution may
 *  exist and be suboptimal.
 *
 *  DP is simply optimized brute force. Instead of immediately jumping to DP, I
 *  should keep it in mind and see if a better solution exists. For this
 *  problem, graph is another intuitive guess.
 *
 *  Surprisingly it is difficult to come up with clear variable names for this
 *  problem. As seen in the DFS solution, to refrain from using standard DFS
 *  names like adj and visted is hard. The issue is that fraction, divisor,
 *  dividend, etc. are somewhat unfamiliar jargon and pretty long. I might have
 *  to think about that more.
 */

/**
 *  DP
 *
 *  Fill in diagonals with 1
 *  dp[i][j] = equation(i, j)
 *  dp[i][j] = dp[i][j - 1] * dp[i + 1][j] (left * bottom)
 *
 *  query(i, j) = dp[i][j]
 *  Invalid indices => -1
 *
 *  Time: O(n^2) where n = # of unique variables
 *  Space: O(n^2)
 */

/**
 *  DFS
 *
 *  Create adjacency list using hash maps
 *  query(a, d) = a->b->c->d = a/b * b/c * c/d * d/d
 *
 *  Time: O(n) where n = # of unique variables
 *  Space: O(n)
 */
class Solution {
 public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
                              vector<double>& values,
                              vector<pair<string, string>> queries) {
    if (equations.empty()) return {};

    // Construct adjacency list
    unordered_map<string, unordered_map<string, double>> adj;
    for (int i = 0; i < equations.size(); ++i) {
      string a = equations[i].first, b = equations[i].second;
      adj[a][b] = values[i];
      adj[b][a] = 1.0 / values[i];
    }

    // DFS through list for each query
    vector<double> solutions;
    for (const auto& query : queries) {
      string a = query.first, b = query.second;
      unordered_set<string> visited;
      solutions.push_back(Query(a, b, adj, visited));
    }

    return solutions;
  }

 private:
  // a / b may take any path from a -> b
  double Query(const string& a, const string& b, auto& adj,
               unordered_set<string>& visited) {
    if (adj.find(a) == adj.end() || visited.find(a) != visited.end()) return -1;
    if (a == b) return 1;
    visited.insert(a);

    // Visit neighbors of dividend (to find alternate path from a -> b) and
    // update expanded quotient
    for (const auto& next : adj[a]) {
      string c = next.first;
      double quotient = next.second;
      double result = Query(c, b, adj, visited);
      if (result != -1) return result * quotient;
    }

    return -1;
  }
};
