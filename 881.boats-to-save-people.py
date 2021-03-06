#
# [917] Boats to Save People
#
# https://leetcode.com/problems/boats-to-save-people/description/
#
# algorithms
# Medium (42.06%)
# Total Accepted:    10.3K
# Total Submissions: 24.5K
# Testcase Example:  '[1,2]\n3'
#
# The i-th person has weight people[i], and each boat can carry a maximum
# weight of limit.
#
# Each boat carries at most 2 people at the same time, provided the sum of the
# weight of those people is at most limit.
#
# Return the minimum number of boats to carry every given person.  (It is
# guaranteed each person can be carried by a boat.)
#
#
#
#
# Example 1:
#
#
# Input: people = [1,2], limit = 3
# Output: 1
# Explanation: 1 boat (1, 2)
#
#
#
# Example 2:
#
#
# Input: people = [3,2,2,1], limit = 3
# Output: 3
# Explanation: 3 boats (1, 2), (2) and (3)
#
#
#
# Example 3:
#
#
# Input: people = [3,5,3,4], limit = 5
# Output: 4
# Explanation: 4 boats (3), (3), (4), (5)
#
# Note:
#
#
# 1 <= people.length <= 50000
# 1 <= people[i] <= limit <= 30000
#
#
#
#
#
#
class Solution(object):
    def numRescueBoats(self, people, limit):
        """
        Sorting + Greedy + Two pointer approach

        Time: O(nlogn)
        Space: O(1)

        :type people: List[int]
        :type limit: int
        :rtype: int
        """

        # O(nlogn)
        people.sort()

        boats = 0
        lo, hi = 0, len(people) - 1
        while lo <= hi:
            boats += 1
            # At least one person goes into the boat
            hi -= 1
            # Check if lightest person (not in boat) can also enter
            if people[lo] + people[hi] <= limit:
                lo += 1

        return boats

