/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (32.38%)
 * Total Accepted:    239.6K
 * Total Submissions: 739.6K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Note:
 *
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
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
 *  "", [] => false
 *  "a", [] => false
 *  "a", ["a"] => true
 *  "abc", ["a", "b", "c", "abc"] => true
 *  "abc", ["a", "ab", c"] => false
 */

/**
 *  DP (tab)
 *
 *  Use a sliding window [j, i) where dp[i] means that s[j..i) is in dict
 *  and dp[j] must be true (j is end of a substring that is in dict)
 *
 *  Time: O(n^3)
 *  Space: O(n)
 */
class Solution {
 public:
  bool wordBreak(string s, vector<string>& word_dict) {
    if (s.length() == 0 || word_dict.empty()) return false;

    int n = s.length();

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    // Convert vector to set for O(1) amortized loop-up time
    unordered_set<string> word_set(word_dict.begin(), word_dict.end());

    int max_length = 0;
    for (const auto& word : word_set) {
      max_length = max(max_length, (int)word.size());
    }

    for (int i = 1; i <= n; ++i) {
      // j is apart from i by a length of the maximum word in dict
      for (int j = i - 1; j >= max(0, i - max_length); --j) {
        dp[i] = dp[j] && word_set.find(s.substr(j, i - j)) != word_set.end();
        if (dp[i]) break;
      }
    }

    return dp[n];
  }
};
