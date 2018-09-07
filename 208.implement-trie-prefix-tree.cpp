/*
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (33.04%)
 * Total Accepted:    130.6K
 * Total Submissions: 393.4K
 * Testcase Example:
 * '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Example:
 *
 *
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");
 * trie.search("app");     // returns true
 *
 *
 * Note:
 *
 *
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 *
 *
 */
#define SIZE 26

class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() { root_ = make_unique<TrieNode>(SIZE); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode* curr = root_.get();
    for (char c : word) {
      if (!curr->children[c - 'a'])
        curr->children[c - 'a'] = make_unique<TrieNode>(SIZE);
      curr = curr->children[c - 'a'].get();
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

 private:
  struct TrieNode {
    bool is_word;
    vector<unique_ptr<TrieNode>> children;
    TrieNode(const int size) {
      is_word = false;
      children.resize(size);
    }
  };

  TrieNode* find(string word) {
    TrieNode* curr = root_.get();
    for (char c : word) {
      TrieNode* child = curr->children[c - 'a'].get();
      if (!child) return nullptr;
      curr = child;
    }
    return curr;
  }

  unique_ptr<TrieNode> root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
