/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (27.91%)
 * Total Accepted:    167.9K
 * Total Submissions: 600.9K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 *
 *
 * Note:
 *
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Sliding Window
 *
 *  Start and end specify substring, use hash map to track char frequencies.
 *
 *  Time: O(n)
 *  Space: O(n)
 */
class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.empty()) return "";

    // Build hash map
    unordered_map<char, int> f;
    for (const auto& c : t) ++f[c];

    int start = 0, end = 0;
    int min_start = start, min_len = INT_MAX;
    int counter = f.size();

    while (end < s.length()) {
      // Expand window until it covers all characters in T
      char end_char = s[end];
      if (f.find(end_char) != f.end()) {
        --f[end_char];
        if (f[end_char] == 0) --counter;
      }
      ++end;

      // If valid, trim start of window for extraneous characters
      while (counter == 0) {
        if (end - start < min_len) {
          min_len = end - start;
          min_start = start;
        }

        // After trimming, update window's validity
        char start_char = s[start];
        if (f.find(start_char) != f.end()) {
          ++f[start_char];
          if (f[start_char] > 0) ++counter;
        }
        ++start;
      }
    }
    if (min_len == INT_MAX) return "";
    return s.substr(min_start, min_len);
  }
};
