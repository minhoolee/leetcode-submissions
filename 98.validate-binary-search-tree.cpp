/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (24.36%)
 * Total Accepted:    273.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's
 * value
 * is 5 but its right child's value is 4.
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
 *  DFS (inorder) approach
 *
 *  Inorder traverse and check that each node is greater than previous
 *
 *  Time: O(n)
 *  Space: O(n)
 *
 *  isValidBST(root):
 *    set res to empty list of integers
 *    set nodes to empty stack of TreeNodes
 *    set curr to root
 *    set prev to null
 *
 *    while curr != null or nodes is not empty:
 *      while curr != null:
 *        add curr to nodes
 *        set curr to curr.left
 *      set curr to nodes.top
 *      remove nodes.top
 *      // BST property: curr > prev in inorder
 *      if prev is not null and curr.val <= prev.val:
 *        return false
 *      set prev to curr
 *      set curr to curr's right
 *    return true
 */
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    std::list<int> res;
    stack<TreeNode*> nodes;
    TreeNode* curr = root;
    TreeNode* prev = nullptr;

    while (curr || !nodes.empty()) {
      while (curr) {
        nodes.push(curr);
        curr = curr->left;
      }
      curr = nodes.top(); nodes.pop();
      if (prev && curr->val <= prev->val) return false;
      prev = curr;
      curr = curr->right;
    }

    return true;
  }
};
