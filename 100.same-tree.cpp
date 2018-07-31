/*
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (48.14%)
 * Total Accepted:    287.1K
 * Total Submissions: 595.6K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * Given two binary trees, write a function to check if they are the same or
 * not.
 *
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
 *
 * Example 1:
 *
 *
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 *
 * ⁠       [1,2,3],   [1,2,3]
 *
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input:     1         1
 * ⁠         /           \
 * ⁠        2             2
 *
 * ⁠       [1,2],     [1,null,2]
 *
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 *
 * ⁠       [1,2,1],   [1,1,2]
 *
 * Output: false
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  First approach
 *
 *  Traverse (post order DFS) and check for equivalence
 *
 *  Time: O(n)
 *  Space: O(1)
 *
 *  isSameTree(p, q):
 *    if p and q are null, return true
 *    else if p is null or q is null, return false
 *
 *    // Neither p or q is null
 *    return isSameTree(p's left, q's left) and
 *           isSameTree(p's right, q's right) and
 *           // Post order traversal, so check root after children
 *           if p's value equals q's value
 */

/**
 *  Test cases
 *
 *  First binary tree is a subtree of the second
 *  [1,2,3],[1,2,3,4] => false
 *
 *  [null],[null] => true
 *  [1],[null] => false
 */
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q)
      return true;
    else if (!p || !q)
      return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) &&
           p->val == q->val;
  }
};
