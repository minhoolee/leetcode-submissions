/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (24.12%)
 * Total Accepted:    104.4K
 * Total Submissions: 431.2K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * Example 1:
 *
 *
 * Input: [10,2]
 * Output: "210"
 *
 * Example 2:
 *
 *
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
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
 *  Some interesting STL <algorithm> functions and a failed attempt at Trie.
 *  I think the Trie approach was not thought through all the way. Perhaps it
 *  would be better to tackle a problem from a simple perspective before a more
 *  advanced one.
 *
 *  I knew sorting was a valid approach, but the optimization of comparing
 *  a + b > b + a string concatenations made the time complexity much
 *  better
 *
 *  As a side note, using #define is nifty for displaying multiple solutions
 */

#define SORT

/**
 *  Sort
 *
 *  Compare by concatenation of num a and num b (this effectively checks
 *  the two permutations and chooses the larger one)
 *
 *  Time: O(nlogn)
 *  Space: O(1)
 */
#ifdef SORT
class Solution {
 public:
#ifdef SIMPLE
  string largestNumber(vector<int>& nums) {
    if (nums.empty()) return "";

    vector<string> num_strs;
    for (const auto& num : nums) {
      num_strs.push_back(to_string(num));
    }

    sort(num_strs.begin(), num_strs.end(),
         [](const string& a, const string& b) { return a + b > b + a; });

    // All 0s collapses into one 0
    if (num_strs[0] == "0") return "0";

    string res;
    for (const auto& num : num_strs) {
      res += num;
    }

    return res;
  }

#else
  string largestNumber(vector<int>& nums) {
    if (nums.empty()) return "";

    // All 0s collapses into one 0
    if (std::all_of(nums.begin(), nums.end(), [](int num) { return num == 0; }))
      return "0";

    vector<string> num_strs;
    std::transform(nums.begin(), nums.end(), std::back_inserter(num_strs),
                   [](int num) { return std::to_string(num); });

    std::sort(num_strs.begin(), num_strs.end(),
              [](const string& a, const string& b) { return a + b > b + a; });

    return std::accumulate(num_strs.begin(), num_strs.end(), string(""));
  }
#endif

 private:
};
#endif

/**
 *  Trie (INCOMPLETE)
 *
 *  Create trie (size 10) and backtrack, checking each node if its word and
 * always going to larger values
 *
 *  OK, I tried to code this for fun but gave up when I realized backtracking
 *  won't work. This solution *almost* works but not quite. I hadn't realized
 *  an exception to the rule. For 3 and 34, 34 goes first because the second
 *  digit of 34 is greater than 3. At this point, it would be easier to just
 *  concatenate 3 and 34 like in the sorting solution, rendering the trie
 *  useless. Waste of time but it was fun.
 *
 *  Time: O(mn) where m is maximum number of digits of one num
 *  Space: O(mn)
 */
#ifdef TRIE
class Trie {
 public:
  struct TrieNode {
    bool is_word;
    map<char, unique_ptr<TrieNode>> children;
    TrieNode(const int size) : is_word(false) {}
  };

  /** Initialize your data structure here. */
  Trie(int size) { root_ = make_unique<TrieNode>(size); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode* curr = root_.get();
    for (char c : word) {
      if (curr->children.find(c) == curr->children.end())
        curr->children[c] = make_unique<TrieNode>(curr->children.size());
      curr = curr->children[c].get();
    }
    curr->is_word = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode* res = find(word);
    return res != nullptr && res->is_word;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) { return find(prefix) != nullptr; }

  TrieNode* root() { return root_.get(); }

 private:
  TrieNode* find(string word) {
    TrieNode* curr = root_.get();
    for (char c : word) {
      if (curr->children.find(c) == curr->children.end()) return nullptr;
      curr = curr->children[c].get();
    }
    return curr;
  }

  unique_ptr<TrieNode> root_;
};

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    Trie trie(kDigits);
    for (const auto& num : nums) {
      trie.insert(std::to_string(num));
    }

    string res;
    string tmp;
    backtrack(trie.root(), res, tmp);

    return res;
  }

 private:
  static constexpr size_t kDigits = 10;

  void backtrack(Trie::TrieNode* root, string& res, string& word) {
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
      char c = it->first;
      auto child = it->second.get();
      word += c;
      if (child->is_word) res += word;
      backtrack(child, res, word);
      word = word.substr(0, word.length() - 1);
    }
  }
};
#endif
