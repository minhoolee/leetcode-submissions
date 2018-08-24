/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (51.65%)
 * Total Accepted:    321.1K
 * Total Submissions: 621.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
 *  Vanilla DFS
 *
 *  Time: O(n)
 *  Space: O(logn), worst case O(n)
 *
 *  inOrderTraversal(root):
 *    set res to empty list of integers
 *    dfs(res, root)
 *    return res
 *
 *  dfs(res, root):
 *    if root is NULL:
 *      return
 *
 *    dfs(root.left)
 *    add root to res
 *    dfs(root.right)
 */
class Solution {
 private:
  void DFS(TreeNode* root, vector<int>& res) {
    if (!root) return;

    DFS(root->left, res);
    res.push_back(root->val);
    DFS(root->right, res);
  }
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;

    DFS(root, res);

    return res;
  }
};
