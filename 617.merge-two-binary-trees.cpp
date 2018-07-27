/*
 * [617] Merge Two Binary Trees
 *
 * https://leetcode.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (68.00%)
 * Total Accepted:    101.5K
 * Total Submissions: 149K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 
 * Given two binary trees and imagine that when you put one of them to cover
 * the other, some nodes of the two trees are overlapped while the others are
 * not. 
 * 
 * 
 * You need to merge them into a new binary tree. The merge rule is that if two
 * nodes overlap, then sum node values up as the new value of the merged node.
 * Otherwise, the NOT null node will be used as the node of new tree.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * Tree 1                     Tree 2                  
 * ⁠         1                         2                             
 * ⁠        / \                       / \                            
 * ⁠       3   2                     1   3                        
 * ⁠      /                           \   \                      
 * ⁠     5                             4   7                  
 * Output: 
 * Merged tree:
 * 3
 * / \
 * 4   5
 * / \   \ 
 * 5   4   7
 * 
 * 
 * 
 * 
 * Note:
 * The merging process must start from the root nodes of both trees.
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
 *  DFS (preorder) both trees at same time, add non-null subtree or sum node
 *
 *  Time: O(n) where n is union of tree 1 and tree 2
 *  Space: O(n)
 *
 *  mergeTrees(t1, t2)
 *    If t1 is null, return t2
 *    If t2 is null, return t1
 *
 *    // Neither are null, sum nodes
 *    Set t1's val to t1's val + t2's val
 *
 *    Set t1's left to mergeTrees(t1->left, t2->left)
 *    Set t1's right to mergeTrees(t1->right, t2->right)
 *
 *    Return t1
 *
 *  // C++ code that modifies input
 *  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
 *    if (!t1) return t2;
 *    if (!t2) return t1;
 *
 *    t1->val += t2->val;
 *
 *    t1->left = mergeTrees(t1->left, t2->left);
 *    t1->right = mergeTrees(t1->right, t2->right);
 *
 *    return t1;
 *  }
 */

/**
 *  Possible other approach (?)
 *
 *  Store t1 and t2 as arrays (similar to heaps) and iterate across array
 *  to create merged tree. Easy to implement but not as efficient
 *
 *  Time: O(m) where m is the greater number of nodes in tree 1 or tree 2
 *  Space: O(m)
 */

class Solution {
 public:
  // Postcondition: t1 and t2 are not modified
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) return t2;
    if (!t2) return t1;

    TreeNode* root = new TreeNode(t1->val + t2->val);

    root->left = mergeTrees(t1->left, t2->left);
    root->right = mergeTrees(t1->right, t2->right);

    return root;
  }
};
