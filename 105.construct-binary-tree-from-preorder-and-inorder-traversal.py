# [105] Construct Binary Tree from Preorder and Inorder Traversal
#
# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
#
# algorithms
# Medium (40.22%)
# Total Accepted:    212.9K
# Total Submissions: 527.5K
# Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
#
# Given preorder and inorder traversal of a tree, construct the binary tree.
#
# Note:
# You may assume that duplicates do not exist in the tree.
#
# For example, given
#
#
# preorder = [3,9,20,15,7]
# inorder = [9,3,15,20,7]
#
# Return the following binary tree:
#
#
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
#
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        Recursive precached approach

        See C++ solution for details

        Time: O(n)
        Space: O(logn) due to recursion

        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        inor_dict = {val : i for i, val in enumerate(inorder)}
        pre_iter = iter(preorder)

        def helper(start, end):
            if start > end: return None
            root_val = next(pre_iter)
            # Advance to next node as root
            root = TreeNode(root_val)
            # Find pivot position of new root in inorder
            idx = inor_dict[root_val]
            root.left = helper(start, idx-1)
            root.right = helper(idx+1, end)
            return root

        return helper(0, len(inorder) - 1)

    def buildTreeSlow(self, preorder, inorder):
        """
        Recursive approach

        See C++ solution for details

        Time: O(n^2)
        Space: O(logn) due to recursion

        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if inorder:
            ind = inorder.index(preorder.pop(0))
            root = TreeNode(inorder[ind])
            root.left = self.buildTree(preorder, inorder[0:ind])
            root.right = self.buildTree(preorder, inorder[ind+1:])
            return root
