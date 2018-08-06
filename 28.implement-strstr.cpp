/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (29.62%)
 * Total Accepted:    299.3K
 * Total Submissions: 1M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
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
 *  Scan through haystack for first letter of needle, and then scan through
 *  rest of needle
 *
 *  Time: O(n*m) where n is length of haystack and m is length of needle 
 *       (can be n^2)
 *  Space: O(1)
 *
 *  strStr(haystack, needle):
 *    set h to haystack's length
 *    set n to needle's length
 *
 *    if needle is empty
 *      return 0
 *
 *    for i in [0..h-n]
 *      if haystack[i] equals needle[0]
 *        for j in [0..n]
 *          if haystack[i+j] does not equal needle[j]
 *            break out of for loop
 *        if j equals n
 *          return i
 *    return -1
 */

/**
 *  Test cases
 *
 *  "testlli", "li" => 5
 *  "abc", "abc" => 0
 *  "abc", "abcd" => -1
 */
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int h = haystack.length();
    int n = needle.length();

    if (n == 0) return 0;

    for (int i = 0; i < h - n + 1; ++i) {
      if (haystack[i] == needle[0]) {
        int j = 0;
        for (; j < n; ++j) {
          if (haystack[i + j] != needle[j]) break;
        }
        if (j == n) return i;
      }
    }
    return -1;
  }
};
