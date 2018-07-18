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
   *
   * // If no strings, return empty string
   * // Set prefix to first string
   * // Loop until end of strings (start with second string)
   *   // Loop until prefix is substring of current string
   *     // Trim prefix's last character
   *     // If prefix is empty string, return empty string
   * // Return prefix
   *
   */

  /**
   * Different approach
   * Binary search the shortest string to find the LCP
   *
   * Time: O(S*log(m)) where S is sum of # of characters of all strings, 
   *       m is length of shortest string
   * Space: O(1)
   * 
   */
  string longestCommonPrefix(vector<string>& strs) {
   // If no strings, return empty string
   if (strs.size() == 0) return "";

   // Set prefix to first string
   string prefix = strs[0];

   // Loop until end of strings (start with second string)
   for (vector<string>::iterator itr = strs.begin()+1; itr != strs.end(); ++itr) {
     // Loop until prefix is substring of current string
     while (itr->find(prefix) != 0)
         // Trim prefix's last character
         prefix = prefix.substr(0, prefix.length()-1);

         // If prefix is empty string, return empty string
         if (prefix.empty()) return "";
   }

   // Return prefix
   return prefix;
  }
};
