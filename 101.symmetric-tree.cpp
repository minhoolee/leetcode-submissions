/*
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (41.10%)
 * Total Accepted:    278.3K
 * Total Submissions: 677.2K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 * But the following [1,2,2,null,3,null,3]  is not:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
 *  Optimal approach (BFS: Preorder)
 *
 *  Check if root is equal and if left and right subtrees are mirrored
 *
 *  Solution is similar to 100.same-tree problem
 *
 *  Time: O(n)
 *  Space: O(n)
 */

class Solution {
 private:
  bool isMirror(TreeNode* p, TreeNode* q) {
    // Check if nodes are both null or equal and
    // left and right subtrees are mirrored
    return !(bool(p) ^ bool(q)) &&
           (!p || (p->val == q->val &&
                   isMirror(p->left, q->right) &&
                   isMirror(p->right, q->left)));
  }

 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
  }
};
