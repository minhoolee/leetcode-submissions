/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.30%)
 * Total Accepted:    363.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

static auto x = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return nullptr;
}();

class Solution {
public:
  // Test cases:
  // "()" -> true
  // "()[]{}" -> true
  // "(]" -> false
  // "([)]" -> false
  // "{[]}" -> true
  // "()}" -> false
  //

  /**
   * First approach
   * Frequency hashtable + direct bracket matching
   *
   * Time: O(n) where n is number of characters
   * Space: O(1)?
   *
   * // Initialize hashtable of character to frequency
   * // Add first character to hashtable
   * // Loop through s until end of string (start at second character)
   *   // Increment curr's frequency
   *   // If curr is ending bracket
   *   // and prev is an opening bracket that doesn't match, return false
   * // Loop through hashtable and see if opening and ending 
   * // If brackets in hashtable to see if opening and closing bracket
   * // frequencies are equal, return false
   * // Return true
   */

  /**
   * Optimal solution
   * Bracket pair hashtable + stack
   *
   * Time: O(n) where n is number of characters
   * Space: O(n)?
   *
   * // Initialize hashtable of opening bracket to closing bracket
   * // Initialize stack of characters
   * // Loop through s
   *   // If stack is empty, push char to stack
   *   // Else if top element of stack is char's pair, pop off top element
   *   // Else push char to stack
   * // Return is stack empty
   */
  bool isValid(string s) {
    // Initialize hashtable of opening bracket to closing bracket
    unordered_map<char, char> tup = {{'(',')'}, {'{','}'}, {'[',']'}};

    // Initialize stack of characters
    stack<char> pairs;

    // Loop through s
    for (char c: s) {
      // If stack is empty, push char to stack
      if (pairs.empty()) pairs.push(c);

      // Else if top element of stack is char's pair, pop off top element
      else if (tup[pairs.top()] == c) pairs.pop();

      // Else push char to stack
      else pairs.push(c);
    }

    // Return is stack empty
    return pairs.empty();
  }
};
