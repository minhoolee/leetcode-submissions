/*
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (33.97%)
 * Total Accepted:    234.8K
 * Total Submissions: 690.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * return its minimum depth = 2.
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
 *  The BFS implementation is useful for keeping track of depth. Instead
 *  of normal BFS (top + pop -> add), it adds a for loop over all nodes
 *  in the current level.
 */

/**
 *  Test cases
 *
 *  empty => 0
 *  1 root => 1
 *  1 root 1 child => 2
 *  1 root 2 child => 2
 *  Ex => 2
 */

/**
 *  DFS
 *
 *  DFS recursively until leaves
 *
 *  Time: O(n)
 *  Space: O(logn), worst case O(n)
 */
/**
 * class Solution {
 *  public:
 *   int minDepth(TreeNode* root) {
 *     if (!root) return 0;
 *     if (!root->left) return minDepth(root->right);
 *     if (!root->right) return minDepth(root->left);
 *     return 1 + min(minDepth(root->left), minDepth(root->right));
 *   }
 * };
 */

/**
 *  BFS
 *
 *  BFS and return depth on smallest depth
 *
 *  Time: O(n)
 *  Space: O(n)
 */
class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);

    int depth = 1;
    while (!q.empty()) {
      // Loop through nodes on same level
      int level_size = q.size();
      for (int i = 0; i < level_size; ++i) {
        TreeNode* node = q.front();
        q.pop();
        if (!node->left && !node->right) return depth;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      ++depth;
    }
    return depth;
  }
};
