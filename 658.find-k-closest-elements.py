#
# [658] Find K Closest Elements
#
# https://leetcode.com/problems/find-k-closest-elements/description/
#
# algorithms
# Medium (34.70%)
# Total Accepted:    31.7K
# Total Submissions: 90.4K
# Testcase Example:  '[1,2,3,4,5]\n4\n3'
#
#
# Given a sorted array, two integers k and x, find the k closest elements to x
# in the array.  The result should also be sorted in ascending order.
# If there is a tie,  the smaller elements are always preferred.
#
#
# Example 1:
#
# Input: [1,2,3,4,5], k=4, x=3
# Output: [1,2,3,4]
#
#
#
#
# Example 2:
#
# Input: [1,2,3,4,5], k=4, x=-1
# Output: [1,2,3,4]
#
#
#
# Note:
#
# The value k is positive and will always be smaller than the length of the
# sorted array.
# ⁠Length of the given array is positive and will not exceed 104
# ⁠Absolute value of elements in the array and x will not exceed 104
#
#
#
#
#
#
# UPDATE (2017/9/19):
# The arr parameter had been changed to an array of integers (instead of a list
# of integers). Please reload the code definition to get the latest changes.
#
#


"""
Notes for improvement
This is first time practicing with whiteboard and with python (switched from
C++).

Mistakes made:
- Need more test cases, figure out how to form unique ones
- // not / for floor division
- Use fewer parentheses in if and loops
- Use lo, hi not low, high
"""

class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        Binary Search

        Binary search for start and then return start : start + k

        Time: O(logn)
        Space: O(1)

        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        lo, hi = 0, len(arr) - k
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if abs(x - arr[mid]) > abs(x - arr[mid + k]):
                lo = mid + 1
            else:
                hi = mid

        return arr[lo : lo + k]
