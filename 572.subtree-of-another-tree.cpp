/*
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (40.39%)
 * Total Accepted:    62.7K
 * Total Submissions: 155.2K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 *
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 *
 *
 * Example 1:
 *
 * Given tree s:
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 *
 * Given tree t:
 *
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 *
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 *
 *
 * Example 2:
 *
 * Given tree s:
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 *
 * Given tree t:
 *
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 *
 * Return false.
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
 *  I think the second solution looks cleaner though longer, especially due to
 *  line splits
 */

/**
 *  DFS
 *
 *  Time: O(m + n)
 *  Space: O(log(max(m, n)) worst O(max(m, n))
 */
/**
 * class Solution {
 *  private:
 *   bool IsSameTree(TreeNode* s, TreeNode* t) {
 *     if (!s && !t) return true;
 *     if (!s || !t) return false;
 *     return s->val == t->val &&
 *            (IsSameTree(s->left, t->left) && IsSameTree(s->right, t->right));
 *   }
 *
 *  public:
 *   bool isSubtree(TreeNode* s, TreeNode* t) {
 *     return s && (IsSameTree(s, t) ||
 *                  (isSubtree(s->left, t) || isSubtree(s->right, t)));
 *   }
 * };
 */
class Solution {
 private:
  bool IsSameTree(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->val != t->val) return false;
    return IsSameTree(s->left, t->left) && IsSameTree(s->right, t->right);
  }

 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s) return false;
    if (IsSameTree(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};
