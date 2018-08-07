/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.89%)
 * Total Accepted:    540.7K
 * Total Submissions: 2.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
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
 *  Store unique substrings of unique characters (using hash table) in a trie
 *
 *  Time: O(n)
 *  Space: O(n*m) where n is length of input string and
 *                      m is length of longest substring
 */

/**
 *  Better approach
 *
 *  Maximum sliding window of unique characters (using hash set)
 *
 *  Time: O(n)
 *  Space: O(min(m, n)) where m is 256 (ASCII)
 *
 *  lengthOfLongestSubstring(s):
 *    set maxLen to 0
 *    set i, j to 0
 *    set n to s's length
 *    init set as empty hash set
 *
 *    while i,j < n
 *      if s[i] is not in set
 *        add s[i] to set
 *        set maxLen to max(maxLen, j - i)
 *      else
 *        delete s[i] from set
 *        increment i
 *
 *    return maxLen
 *
 *  int lengthOfLongestSubstring(string s) {
 *    int maxLen = 0;
 *    int n = s.length();
 *    int i = 0, j = 0;
 *
 *    unordered_set<char> set;
 *
 *    while (i < n && j < n) {
 *      if (set.find(s[j]) == set.end()) {
 *        set.insert(s[j++]);
 *        maxLen = max(maxLen, j - i);
 *      } else {
 *        set.erase(s[i++]);
 *      }
 *    }
 *
 *    return maxLen;
 *  }
 */

/**
 *  Optimal approach
 *
 *  Maximum sliding window of unique characters (using hash set) that
 *  resizes window to skip duplicates
 *
 *  Time: O(n)
 *  Space: O(min(m, n)) where m is 256 (ASCII)
 *
 *  lengthOfLongestSubstring(s):
 *    set maxLen to 0
 *    set i to 0
 *    set n to s's length
 *
 *    init map as empty hash map of char to int
 *
 *    for j in [0..n]
 *      if s[j] is in map
 *        // Duplicate may be from before sliding window because duplicates
 *        // update when j passes them in sliding window
 *        set i to max(map[s[j]] + 1, i)
 *
 *        // Update duplicate
 *        set map[s[j]] to j
 *      else
 *        add {s[j], i} to map
 *
 *      set maxLen to max(maxLen, j - i + 1)
 *
 *    return maxLen
 */

/**
 *  Test cases
 *
 *  "" => 0
 *  "a" => 1
 *  "1" => 1
 *  "abad" => 3
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    int n = s.length();

    unordered_map<char, int> map;

    for (int i = 0, j = 0; j < n; ++j) {
      unordered_map<char, int>::iterator it = map.find(s[j]);

      if (it != map.end()) {
        i = max(it->second + 1, i);
        it->second = j;
      } else {
        map.insert(make_pair(s[j], j));
      }

      // Duplicates have been removed
      maxLen = max(maxLen, j - i + 1);
    }

    return maxLen;
  }
};
