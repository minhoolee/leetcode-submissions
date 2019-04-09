#
# [200] Number of Islands
#
# https://leetcode.com/problems/number-of-islands/description/
#
# algorithms
# Medium (40.88%)
# Total Accepted:    327.8K
# Total Submissions: 801.9K
# Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
#
# Given a 2d grid map of '1's (land) and '0's (water), count the number of
# islands. An island is surrounded by water and is formed by connecting
# adjacent lands horizontally or vertically. You may assume all four edges of
# the grid are all surrounded by water.
#
# Example 1:
#
#
# Input:
# 11110
# 11010
# 11000
# 00000
#
# Output: 1
#
#
# Example 2:
#
#
# Input:
# 11000
# 11000
# 00100
# 00011
#
# Output: 3
#
#
class Solution(object):
    DIRS = [[0, -1],
            [0, 1],
            [1, 0],
            [-1, 0]]

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        ans = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.DFS(grid, i, j)
                    ans += 1

        return ans

    def DFS(self, grid, i, j):
        if i < 0 or i >= len(grid) or \
           j < 0 or j >= len(grid[0]) or \
           grid[i][j] == '0':
            return

        grid[i][j] = '0'

        for d in self.DIRS:
            self.DFS(grid, i + d[0], j + d[1])


