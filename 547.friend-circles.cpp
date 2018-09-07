/*
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (49.89%)
 * Total Accepted:    47.8K
 * Total Submissions: 95.9K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 *
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 *
 *
 *
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 *
 *
 * Example 1:
 *
 * Input:
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 *
 *
 *
 *
 * Note:
 *
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  DFS (inorder)
 *
 *  Iteratively DFS while checking visited. Final circles = n - visited + 1
 *
 *  Time: O(n^2)
 *  Space: O(n)
 */
class Solution {
 private:
  // void DFS(vector<vector<int>>& M, vector<bool>& visited, int student) {
  //   stack<int> friends;
  //   friends.push(student);
  //   while (!friends.empty()) {
  //     int i = friends.top();
  //     friends.pop();
  //
  //     // Add friends to facebook
  //     for (int j = 0; j < M.size(); ++j) {
  //       if (M[i][j] == 1 && !visited[j]) {
  //         visited[j] = true;
  //         friends.push(j);
  //       }
  //     }
  //   }
  // }

  void DFS(vector<vector<int>>& M, vector<bool>& visited, int i) {
    for (int j = 0; j < M.size(); ++j) {
      if (M[i][j] == 1 && !visited[j]) {
        visited[j] = true;
        DFS(M, visited, j);
      }
    }
  }

 public:
  int findCircleNum(vector<vector<int>>& M) {
    if (M.empty() || M[0].empty()) return 0;

    int n = M.size();
    int group_count = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        visited[i] = true;
        DFS(M, visited, i);
        ++group_count;  // Increment group count when visiting new groups
      }
    }

    return group_count;
  }
};
