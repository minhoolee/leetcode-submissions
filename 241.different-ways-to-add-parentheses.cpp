/*
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (47.27%)
 * Total Accepted:    61.3K
 * Total Submissions: 129.7K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 *
 * Example 1:
 *
 *
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 * Example 2:
 *
 *
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
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
 *  I thought for this problem I'd need a stack since it seems like a
 *  calculator problem. However, it's really a straightforward DP problem that
 *  becomes more apparent when looking at the patterns in the "Explanation"
 *  section. Of course, this will have to be self-generated in the interview.
 */

/**
 *  DP (memo)
 *
 *  For every operator, the left and right hand side is every way to compute
 *  the left and right hand side.
 *
 *  I.e. let i = index of some operator
 *  diffWaysToCompute(input) for operator i =
 *    diffWaysToCompute(input[0:i)) + diffWaysToCompute(input(i:input.length))
 *
 *  diffWaysToCompute(input) = diffWaysToCompute(input) for all operators
 *
 *  Time: O(n), worst O(3^n)
 *  Space: O(n^2)
 */
class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    if (input.empty()) return {};

    unordered_map<string, vector<int>> memo;
    return diffWaysToCompute(input, memo);
  }

 private:
  unordered_set<char> operators = {'+', '-', '*'};

  vector<int> diffWaysToCompute(const string& input,
                                unordered_map<string, vector<int>>& memo) {
    if (memo.find(input) != memo.end()) return memo[input];
    vector<int> res;

    for (int i = 0; i < input.length(); ++i) {
      char c = input[i];
      if (operators.find(c) != operators.end()) {
        string left = input.substr(0, i);
        string right = input.substr(i + 1);
        vector<int> l_perms = diffWaysToCompute(left, memo);
        vector<int> r_perms = diffWaysToCompute(right, memo);

        for (int l : l_perms) {
          for (int r : r_perms) {
            int curr_res = 0;
            switch (c) {
              case '+':
                curr_res = l + r;
                break;
              case '-':
                curr_res = l - r;
                break;
              case '*':
                curr_res = l * r;
                break;
            }
            res.push_back(curr_res);
          }
        }
      }
    }
    if (res.empty()) res.push_back(stoi(input));
    memo[input] = res;
    return res;
  }
};
