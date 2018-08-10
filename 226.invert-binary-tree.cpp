/*
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (54.54%)
 * Total Accepted:    251.3K
 * Total Submissions: 460.7K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Invert a binary tree.
 *
 * Example:
 *
 * Input:
 *
 *
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 *
 * Output:
 *
 *
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 *
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 *
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you
 * can’t invert a binary tree on a whiteboard so f*** off.
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
 *  Notes for improvement
 *
 *  Note that invertTree(root->left) returns the previous left node. Use this
 *  for swapping without a temp variable
 */

/**
 *  DFS Approach
 *
 *  Preorder traverse tree recursively, swap left and right nodes until null
 *
 *  Time: O(n)
 *  Space: O(n)
 *
 *  swapChildren(root):
 *    set tmp to root's left
 *    set root's left to root's right
 *    set root's right to tmp
 *
 *  invertTree(root):
 *    if root is null
 *      return null
 *
 *    swapChildren(root)
 *    invertTree(root's left)
 *    invertTree(root's right)
 *
 *    return root
 */
class Solution {
 private:
  // Precondition: root is not null
  void swapChildren(TreeNode* root) {
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
  }

 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;

    swapChildren(root);
    invertTree(root->left);
    invertTree(root->right);

    return root;
  }
};
