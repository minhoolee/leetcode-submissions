/*
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (51.90%)
 * Total Accepted:    67K
 * Total Submissions: 129.3K
 * Testcase Example:  '"USA"'
 *
 *
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 *
 *
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 *
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one
 * letter, like "Google".
 *
 * Otherwise, we define that this word doesn't use capitals in a right way.
 *
 *
 *
 * Example 1:
 *
 * Input: "USA"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "FlaG"
 * Output: False
 *
 *
 *
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase
 * latin letters.
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Bit Operation
 *
 *  Time: O(n)
 *  Space: O(1)
 */
class Solution {
 public:
  bool detectCapitalUse(string word) {
    int capital_count = 0;

    for (const char c : word) {
      if (IsCapital(c)) {
        ++capital_count;
      }
    }

    return (capital_count == 0 || capital_count == word.size()) ||
           (capital_count == 1 && IsCapital(word[0]));
  }

 private:
  // Capital letters don't have 6th bit set but lowercase letters do
  bool IsCapital(char c) { return !(c & (1 << (6 - 1))); }
};
