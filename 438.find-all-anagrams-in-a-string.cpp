/*
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Easy (34.20%)
 * Total Accepted:    76.5K
 * Total Submissions: 223.5K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Sliding window
 *
 *  Same as normal sliding window but anagram must have predefined length
 *
 *  Time: O(n)
 *  Space: O(n)
 */
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    if (s.empty() || p.empty()) return ans;

    unordered_map<char, int> f;
    for (const auto& c : p) ++f[c];

    int start = 0, end = 0;
    int len = p.length();
    int counter = f.size();

    while (end < s.length()) {
      char end_char = s[end];
      if (f.find(end_char) != f.end()) {
        --f[end_char];
        if (f[end_char] == 0) --counter;
      }
      ++end;

      while (counter == 0) {
        if (end - start == len) ans.push_back(start);

        char start_char = s[start];
        if (f.find(start_char) != f.end()) {
          ++f[start_char];
          if (f[start_char] > 0) ++counter;
        }
        ++start;
      }
    }
    return ans;
  }
};
