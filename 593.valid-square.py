#
# [593] Valid Square
#
# https://leetcode.com/problems/valid-square/description/
#
# algorithms
# Medium (39.92%)
# Total Accepted:    16.3K
# Total Submissions: 40.8K
# Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
#
# Given the coordinates of four points in 2D space, return whether the four
# points could construct a square.
#
# The coordinate (x,y) of a point is represented by an integer array with two
# integers.
#
# Example:
#
# Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
# Output: True
#
#
#
# ⁠Note:
#
# All the input integers are in the range [-10000, 10000].
# A valid square has four equal sides with positive length and four equal
# angles (90-degree angles).
# Input points have no order.
#
#
#

import math

def vector(p1, p2):
    return [i - j for i, j in zip(p1, p2)]

def length(v):
    return math.sqrt(sum([a ** 2 for a in v]))

class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """

        points = [p1, p2, p3, p4]
        unique_lengths = set()

        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                v = vector(points[i], points[j])
                l = length(v)
                if l == 0:
                    return False
                unique_lengths.add(l)

        return len(unique_lengths) == 2
