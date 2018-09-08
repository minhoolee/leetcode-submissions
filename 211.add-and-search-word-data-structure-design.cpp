/*
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (26.69%)
 * Total Accepted:    86K
 * Total Submissions: 321.2K
 * Testcase Example:
 * '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports the following two operations:
 *
 *
 * void addWord(word)
 * bool search(word)
 *
 *
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 *
 * Example:
 *
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 *
 *
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 *
 */

/**
 *  Notes for improvement
 *
 *  Pretty clever tricks in this program for using c string. While not
 *  recommend, c strings will speed up processing time significantly. Not sure
 *  if that warrants using it in interview...
 *
 *  BTW, I should figure this out eventually; defaultdict in python seems cool
 *  https://leetcode.com/problems/implement-trie-prefix-tree/discuss/58887/python-each-function-only-one-line
 */

#define SIZE 26

class WordDictionary {
 public:
  /** Initialize your data structure here. */
  WordDictionary() { root_ = make_unique<TrieNode>(SIZE); }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    TrieNode* curr = root_.get();
    for (const char c : word) {
      if (!curr->children[c - 'a'])
        curr->children[c - 'a'] = make_unique<TrieNode>(SIZE);
      curr = curr->children[c - 'a'].get();
    }
    curr->is_word = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) { return search_from(root_.get(), word.c_str()); }

 private:
  struct TrieNode {
    bool is_word;
    vector<unique_ptr<TrieNode>> children;
    TrieNode(int size) {
      is_word = false;
      children.resize(size);
    }
  };

  bool search_from(TrieNode* root, const char* word) {
    TrieNode* curr = root;
    // Pretty clever way of iterating through c string (null terminating)
    for (int i = 0; i < word[i]; ++i) {
      char c = word[i];

      // If character is '.' or exists in trie, move to it
      if (c == '.') {
        // Visit all children if character is '.'
        for (const auto& child : curr->children) {
          if (child != nullptr &&
              /* PRETTY CLEVER: word + i + 1 to do word.substr(i + 1, end) */
              search_from(child.get(), word + i + 1))
            return true;
        }
        return false;
      } else if (curr->children[c - 'a']) {
        curr = curr->children[c - 'a'].get();
      } else {
        return false;
      }
    }
    return curr != nullptr && curr->is_word;
  }

  unique_ptr<TrieNode> root_;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
