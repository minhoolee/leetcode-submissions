/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (35.81%)
 * Total Accepted:    156.4K
 * Total Submissions: 436.5K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
 *  Divide and conquer approach
 *
 *  Find pivot using preorder list to divide and conquer inorder list
 *
 *  Time: O(nlogn) or O(n^2) for skewed
 *  Space: O(n)
 *
 *  This maps easily to python (list slicing) but not C++
 *
 *  buildTree(preorder, inorder):
 *    if inorder is empty
 *      return null
 *
 *    set r to preorder[0]
 *    set pivot to index of r in inorder
 *
 *    set root to new node of value r
 *    set root's left to buildTree(preorder[1..pivot], inorder[0..pivot-1])
 *    set root's right to buildTree(preorder[pivot+1..preorder's length],
 *                                  inorder[pivot+1..inorder's length])
 *
 *    return root
 *
 *  C++ suited pseudocode
 *
 *  set rootInd to 0
 *
 *  helper(preorder, inorder, inStart, inEnd)
 *    // Inorder is empty or preorder has been fully traversed
 *    if (inStart > inEnd || rootInd > preorder's length - 1)
 *      return null
 *
 *    set rootVal to preorder[rootInd]
 *    set pivot to index of rootVal in inorder
 *
 *    // Preorder goes through base root -> left roots -> right roots
 *    // Incrementing loop counter acts similarly to popping off current root
 *    increment rootInd
 *
 *    set root to new node of value rootVal
 *    set root's left to helper(preorder, inorder, rootInd, inStart, pivot - 1)
 *    set root's right to helper(preorder, inorder, rootInd, pivot + 1, inEnd)
 *
 *    return root
 *
 *  buildTree(preorder, inorder):
 *    return helper(preorder, inorder, rootInd, 0, inorder's length - 1)
 */
class Solution {
  TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& rootInd,
                   int inStart, int inEnd) {

    if (inStart > inEnd || rootInd > preorder.size() - 1) return NULL;

    int rootVal = preorder[rootInd];
    int pivot = std::find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();

    // Preorder goes through base root -> left roots -> right roots
    // Incrementing loop counter acts similarly to popping off current root
    ++rootInd;

    TreeNode* root = new TreeNode(rootVal);
    root->left = helper(preorder, inorder, rootInd, inStart, pivot - 1);
    root->right = helper(preorder, inorder, rootInd, pivot + 1, inEnd);

    return root;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int rootInd = 0;
    return helper(preorder, inorder, rootInd, 0, inorder.size() - 1);
  }
};
