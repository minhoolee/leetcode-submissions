/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.63%)
 * Total Accepted:    358K
 * Total Submissions: 1.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Mirror around center approach
 *
 *  Find maximum mirror around center for all 2N - 1 centers
 *
 *  P(i, j) := P(i + 1, j - 1) and A[i] = A[j]
 *  Base case (center or center between duplicates):
 *    P(i, i) := true
 *    P(i, i + 1) := A[i] = A[i + 1]
 *
 *  Time: O(n^2)
 *  Space: O(1)
 *
 *  longestPalindrome(s):
 *    set start to 0, end to 0
 *
 *    for i in [0..n-1):
 *      set len1 to expandAroundCenter(s, i, i)
 *      set len2 to expandAroundCenter(s, i, i + 1)
 *      set len to max(len1, len2)
 *
 *      // Expand start and end by half of length
 *      if len > (end - start + 1):
 *        set start to i - (len - 1) / 2
 *        set end to i + len / 2
 *
 *    return s[start, end]
 *
 *  expandAroundCenter(s, start, end):
 *    while start >= 0 and end < s.length and s[start] = s[end]:
 *      decrement start
 *      increment end
 *    // Same thing as end - start + 1 if s[start] still = s[end]
 *    return end - start - 1
 */

/**
 *  Test cases
 *
 *  baabad => baab
 *  abcd => a or b or c or d
 */
class Solution {
 private:
  int expandAroundCenter(const string& s, int start, int end) {
    while (start >= 0 && end < s.length() && s[start] == s[end]) {
      --start;
      ++end;
    }
    return end - start - 1;
  }

 public:
  string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, end = 0;

    for (int i = 0; i < s.length() - 1; ++i) {
      int len1 = expandAroundCenter(s, i, i);
      int len2 = expandAroundCenter(s, i, i + 1);
      int len = std::max(len1, len2);

      if (len > (end - start + 1)) {
        start = i - (len - 1) / 2;
        end = i + len / 2;
      }
    }

    return s.substr(start, end - start + 1);
  }
};
