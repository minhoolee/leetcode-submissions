#
# [878] Shifting Letters
#
# https://leetcode.com/problems/shifting-letters/description/
#
# algorithms
# Medium (37.93%)
# Total Accepted:    9.5K
# Total Submissions: 24.9K
# Testcase Example:  '"abc"\n[3,5,9]'
#
# We have a string S of lowercase letters, and an integer array shifts.
#
# Call the shift of a letter, the next letter in the alphabet, (wrapping around
# so that 'z' becomes 'a'). 
#
# For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
#
# Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x
# times.
#
# Return the final string after all such shifts to S are applied.
#
# Example 1:
#
#
# Input: S = "abc", shifts = [3,5,9]
# Output: "rpl"
# Explanation:
# We start with "abc".
# After shifting the first 1 letters of S by 3, we have "dbc".
# After shifting the first 2 letters of S by 5, we have "igc".
# After shifting the first 3 letters of S by 9, we have "rpl", the answer.
#
#
# Note:
#
#
# 1 <= S.length = shifts.length <= 20000
# 0 <= shifts[i] <= 10 ^ 9
#
#
#
class Solution(object):
    NUM_CHARS = 26

    def shift(self, c, amount):
        curr = ord(c) - ord('a')
        return chr((ord('a') + (curr + amount) % self.NUM_CHARS))

    def shiftingLetters(self, S, shifts):
        """
        One-pass approach
        :type S: str
        :type shifts: List[int]
        :rtype: str
        """
        total_shift = sum(shifts)
        shifted_S = ""
        for i in range(0, len(S)):
            shifted_S += self.shift(S[i], total_shift)
            total_shift -= shifts[i]
        return shifted_S



