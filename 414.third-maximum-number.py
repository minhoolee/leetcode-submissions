#
# [414] Third Maximum Number
#
# https://leetcode.com/problems/third-maximum-number/description/
#
# algorithms
# Easy (28.50%)
# Total Accepted:    80.3K
# Total Submissions: 281.8K
# Testcase Example:  '[3,2,1]'
#
# Given a non-empty array of integers, return the third maximum number in this
# array. If it does not exist, return the maximum number. The time complexity
# must be in O(n).
#
# Example 1:
#
# Input: [3, 2, 1]
#
# Output: 1
#
# Explanation: The third maximum is 1.
#
#
#
# Example 2:
#
# Input: [1, 2]
#
# Output: 2
#
# Explanation: The third maximum does not exist, so the maximum (2) is returned
# instead.
#
#
#
# Example 3:
#
# Input: [2, 2, 3, 1]
#
# Output: 1
#
# Explanation: Note that the third maximum here means the third maximum
# distinct number.
# Both numbers with value 2 are both considered as second maximum.
#
#
#

import heapq

class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # Max heap (largest to smallest)
        heap = [float('-inf'), float('-inf'), float('-inf')]
        for n in nums:
            if n not in heap:
                if n > heap[0]: heap = [n, heap[0], heap[1]]
                elif n > heap[1]: heap = [heap[0], n, heap[1]]
                elif n > heap[2]: heap = [heap[0], heap[1], n]

        return max(nums) if float('-inf') in heap else heap[2]


# Sort of a built in heapq solution. Python doesn't seem to have a nice priority queue / heap
#
# https://leetcode.com/problems/third-maximum-number/discuss/90350/python-2-5-lines-on-time-o1-space
#
# def thirdMax(self, nums):
#    l = [float('-inf')] * 3
#    for n in nums:
#        if n > l[0] and n not in l:
#            heapq.heappushpop(l, n)
#    return l[0] if l[0] != float('-inf') else max(l)

