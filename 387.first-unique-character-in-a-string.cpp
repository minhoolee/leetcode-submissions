/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.53%)
 * Total Accepted:    157.6K
 * Total Submissions: 331.5K
 * Testcase Example:  '"leetcode"'
 *
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 *
 *
 *
 * Note: You may assume the string contain only lowercase letters.
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Hash Map
 *
 *  Time: O(n)
 *  Space: O(n)
 */
class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_map<char, int> f;
    for (char c : s) {
      ++f[c];
    }
    for (int i = 0; i < s.length(); ++i) {
      if (f[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
