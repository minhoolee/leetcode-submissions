/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.40%)
 * Total Accepted:    220K
 * Total Submissions: 901.8K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 *
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 * Example 4:
 *
 *
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
 *
 *
 * Example 5:
 *
 *
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Test cases
 *
 *  s = "", p = "" => true
 *  s = "a", p = "" => false
 *  s = "", p = "a" => false
 *  s = "", p = "a*" => true
 *  s = "", p = "a*b*c*" => true
 *  s = "abc", p = "abc*" => true
 *  s = "abc", p = "*abc" => false
 */

/**
 *  Recursion
 *
 *  Each call checks first letter (char) to see if s and p match
 *  1. remove char(s) and char(p) (matching)
 *  2. remove char + * from p (no matching)
 *  3. remove char(s) from s (matching)
 *
 *  2 and 3 can be combined to one line that checks for char(p) = *
 *
 *  Time: something weird close to O(n)?
 *  Space: something weird close to O(n^2)?
 */

/**
 *  DP (tab)
 *
 *  2D DP, can be done with 1D trivially
 *  https://www.youtube.com/watch?v=l3hda49XcDE&list=PLrmLmBdmIlpuE5GEMDXWf0PWbBD9Ga1lO
 *
 *  dp[m + 1][n + 1] where m = s.length, n = p.length
 *  dp[i][j] = regex match of s[0:i) and p[0:j), both exclusive
 *
 *  dp[0][0] = true
 *  dp[i][j] =
 *    1. dp[i - 1][j - 1] if char match or p char is .
 *    2. dp[i][j - 2] if p char is * (remove 2 from p)
 *    3. dp[i - 1][j] if p char is * and s[i - 1] = p[j - 1] (remove 1 from s)
 *
 *  The third case is most difficult to come up with because
 *  s = aaaaaaaa, p = a* needs to be processed one step at a time
 *
 *  Time: O(m * n)
 *  Space: O(m * n)
 */
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
    dp[0][0] = true;

    // Take care of edge case where s is empty and p has *
    // E.g. s = "", p = "a*b*c*"
    for (int j = 2; j < n + 1; ++j) {
      if (p[j - 1] == '*') {
        dp[0][j] = dp[0][j - 2];
      }
    }

    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        // s char and p char match
        if (s[i - 1] == p[j - 1] || p[j - 1] == '.') 
          dp[i][j] = dp[i - 1][j - 1];

        // p char is * and two char from p can be removed
        else if (p[j - 1] == '*' && j >= 2 && dp[i][j - 2])
          dp[i][j] = dp[i][j - 2];

        // p char is * and s char equals char before *
        else if (p[j - 1] == '*' && j >= 2 &&
                 (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
          dp[i][j] = dp[i - 1][j];
      }
    }

    return dp[m][n];
  }
};
