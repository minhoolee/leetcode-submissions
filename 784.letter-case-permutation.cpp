/*
 * [800] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (53.34%)
 * Total Accepted:    23.4K
 * Total Submissions: 44K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible
 * strings we could create.
 *
 *
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 *
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 *
 * Input: S = "12345"
 * Output: ["12345"]
 *
 *
 * Note:
 *
 *
 * S will be a string with length at most 12.
 * S will consist only of letters or digits.
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Notes for improvement
 *
 *  One could use trick here: toggle_case can be replaced with c ^ 32
 *  This works because 
 *  'A' = 65 = 1000001
 *  'a' = 97 = 1100001
 *  Toggling 5th bit changes case
 */

/**
 *  Backtracking
 *
 *  Backtrack through each character, adding lower & upper if not number
 *
 *  Time: O(2^n)
 *  Space: O(logn)
 */
class Solution {
 private:
  char toggle_case(char c) {
    if (isupper(c))
      return tolower(c);
    else if (islower(c))
      return toupper(c);
    return '\0';
  }

  void backtrack(string S, int curr, vector<string>& res) {
    res.push_back(S);
    if (curr == S.size()) return;

    for (int i = curr; i < S.length(); ++i) {
      if (isalpha(S[i])) {
        S[i] = toggle_case(S[i]);
        backtrack(S, i + 1, res);
        S[i] = toggle_case(S[i]);
      }
    }
  }
 public:
  vector<string> letterCasePermutation(string S) {
    if (S.empty()) return {""};
    vector<string> res;
    backtrack(S, 0, res);
    return res;
  }
};
