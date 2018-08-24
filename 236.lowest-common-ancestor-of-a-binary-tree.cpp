/*
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (31.19%)
 * Total Accepted:    187.4K
 * Total Submissions: 599.9K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 *
 *
 * ⁠       _______3______
 * ⁠      /              \
 * ⁠   ___5__          ___1__
 * ⁠  /      \        /      \
 * ⁠  6      _2       0       8
 * ⁠        /  \
 * ⁠        7   4
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of of nodes 5 and 1 is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself
 * ⁠            according to the LCA definition.
 *
 * Note:
 *
 *
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.
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
 *  Recursive approach
 *
 *  Run LCA on left and right subtrees. LCA returns null if no LCA found.
 *  Three possible cases
 *  1. No subtree has non-null LCA -> return null
 *  2. Only one subtree has non-null LCA -> return non-null LCA
 *  3. Both subtrees have non-null LCA -> return root
 *
 *  Key is to assume function works and use it to your advantage
 *
 *  Time: O(n)
 *  Space: O(logn), worst case O(n)
 *
 *  lowestCommonAncestor(root, p, q):
 *    if root is null or root = p or root = q:
 *      return root
 *    left = lowestCommonAncestor(root.left, p, q)
 *    right = lowestCommonAncestor(root.right, p, q)
 *    return root if left and right are not null else left or right
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    /* return left && right ? root : (!left ? right : left); */
    if (!left)
      return right;
    else if (!right)
      return left;
    else
      return root;
  }
};
