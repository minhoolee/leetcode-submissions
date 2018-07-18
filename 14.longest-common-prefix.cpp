/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.76%)
 * Total Accepted:    296.5K
 * Total Submissions: 933.4K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
  // Test cases:
  // ["flower","flow","flight"] -> "fl"
  // ["dog","racecar","car"] -> ""
  // ["a","a","a"] -> "a"
  // ["abc","abcd","abcde"] -> "abc"
  // ["flower","flow","flight","a"] -> ""
  // [] -> ""

  /**
   * First approach
   * Better than brute force of checking single character across all strings
   *
   * Time: O(S) where S is sum of # of characters of all strings
   * Space: O(1)
   *
   * // If no strings, return empty string
   * // Set prefix to first string
   * // Loop until end of strings (start with second string)
   *   // Loop until current string starts with prefix
   *     // Trim prefix's last character
   *     // If prefix is empty string, return empty string
   * // Return prefix
   *
   * string longestCommonPrefix(vector<string>& strs) {
   *   // If no strings, return empty string
   *   if (strs.size() == 0) return "";
   *
   *   // Set prefix to first string
   *   string prefix = strs[0];
   *
   *   // Loop until end of strings (start with second string)
   *   for (vector<string>::iterator it = strs.begin()+1; it != strs.end(); ++it) {
   *     // Loop until current string starts with prefix
   *     while (it->find(prefix) != 0)
   *         // Trim prefix's last character
   *         prefix = prefix.substr(0, prefix.length()-1);
   *
   *         // If prefix is empty string, return empty string
   *         if (prefix.empty()) return "";
   *   }
   *
   *   // Return prefix
   *   return prefix;
   * }
   */

  /**
   * Different approach
   * Binary search the shortest string to find the LCP
   *
   * Time: O(S*log(m)) where S is sum of # of characters of all strings, 
   *       m is length of shortest string
   * Space: O(1)
   */
  string longestCommonPrefix(vector<string>& strs) {
    // If no strings, return empty string
    if (strs.size() == 0) return "";

    // Set minLen to max value
    int minLen = INT_MAX;

    // Set shortest to first string
    string shortest = strs[0];

    // Loop until end of strings
    for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
      // If string length shorter than minLen, set minLen to string length 
      // and shortest to shortest string
      if (minLen > it->length()) {
        minLen = it->length();
        shortest = *it;
      }
    }

    // Set low to 0, high to minLen
    int low = 0, high = minLen;

    // Loop until low is greater than high
    while (low <= high) {
      // Set mid to (low + high) / 2
      int mid = (low + high) / 2;

      // If [0...mid-1] is a common prefix, set low to mid + 1
      if (isCommonPrefix(strs, shortest, mid))
        low = mid + 1;
      // Else set high to mid - 1
      else
        high = mid - 1;
    }
    // Return [0...((low + high)/2) - 1] substring of first string
    return shortest.substr(0, (low + high)/2);
  }

  // Returns true if common prefix, false if not
  bool isCommonPrefix(vector<string>& strs, string shortest, int len) {
    // Set prefix to substring [0...len-1] of shortest
    string prefix = shortest.substr(0, len);

    // Loop through strings
    for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
      // If prefix is not beginning of current string, return false
      if (it->find(prefix) != 0)
        return false;
    }
    // Return true
    return true;
  }
};
