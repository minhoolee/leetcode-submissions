/*
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (48.87%)
 * Total Accepted:    53.1K
 * Total Submissions: 108.7K
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 *
 *
 * Example:
 *
 * Input: The root of a Binary Search Tree like this:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 *
 * Output: The root of a Greater Tree like this:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
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
 *  DFS (reverse inorder)
 *
 *  Time: O(n)
 *  Space: O(logn) worst case O(n)
 */
class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    TreeNode* curr = root;
    stack<TreeNode*> s;

    while (!s.empty() || curr) {
      // Add curr (root) and then right subtree
      while (curr) {
        s.push(curr);
        curr = curr->right;
      }

      curr = s.top(), s.pop();
      sum += curr->val;
      curr->val = sum;

      // Move to left subtree and start over
      curr = curr->left;
    }

    return root;
  }
};
