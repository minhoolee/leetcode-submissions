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
 *  Notes for improvement
 *
 *  This is an archetypal union-find problem, but if you don't know union-find,
 *  the DFS is pretty clear too.
 *
 *  Note that the union-find implementation is not optimal but is only three
 *  lines long (and fairly clear). It could be improved with path compression
 *  and union by rank, but the latter would decrease code clarity unless the
 *  disjoint set structure is abstractified and stores rank (otherwise need
 *  another array to keep track of rank).
 */

/**
 *  DFS (inorder)
 *
 *  Iteratively DFS while checking visited. Final circles = n - visited + 1
 *
 *  Time: O(n^2)
 *  Space: O(n)
 */
/**
 * class Solution {
 *  private:
 *   // void DFS(vector<vector<int>>& M, vector<bool>& visited, int student) {
 *   //   stack<int> friends;
 *   //   friends.push(student);
 *   //   while (!friends.empty()) {
 *   //     int i = friends.top();
 *   //     friends.pop();
 *   //
 *   //     // Add friends to facebook
 *   //     for (int j = 0; j < M.size(); ++j) {
 *   //       if (M[i][j] == 1 && !visited[j]) {
 *   //         visited[j] = true;
 *   //         friends.push(j);
 *   //       }
 *   //     }
 *   //   }
 *   // }
 *
 *   void DFS(vector<vector<int>>& M, vector<bool>& visited, int i) {
 *     for (int j = 0; j < M.size(); ++j) {
 *       if (M[i][j] == 1 && !visited[j]) {
 *         visited[j] = true;
 *         DFS(M, visited, j);
 *       }
 *     }
 *   }
 *
 *  public:
 *   int findCircleNum(vector<vector<int>>& M) {
 *     if (M.empty() || M[0].empty()) return 0;
 *
 *     int n = M.size();
 *     int group_count = 0;
 *     vector<bool> visited(n, false);
 *     for (int i = 0; i < n; ++i) {
 *       if (!visited[i]) {
 *         visited[i] = true;
 *         DFS(M, visited, i);
 *         ++group_count;  // Increment group count when visiting new groups
 *       }
 *     }
 *
 *     return group_count;
 *   }
 * };
 */

/**
 *  Union Find
 *
 *  Simple union-find solution that isn't optimal but is super concise. This
 *  problem is an archetypal union-find problem.
 *
 *  Time: O(nlogn) worst case O(n^2)
 *  Space: O(n)
 */
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    if (M.empty() || M[0].empty()) return 0;

    int m = M.size();
    int group_count = 0;
    vector<int> root(m, 0);

    // Make set (initialize each set as disjoint)
    for (int i = 0; i < m; ++i) root[i] = i;

    // Join sets that are friends (only one half of matrix is needed)
    for (int i = 0; i < m; ++i) {
      for (int j = i + 1; j < m; ++j) {
        if (M[i][j] == 1) {
          UnionFind(root, i, j);
        }
      }
    }

    // Count number of disjoint sets
    for (int i = 0; i < m; ++i) {
      if (root[i] == i) {
        ++group_count;
      }
    }

    return group_count;
  }

 private:
  void UnionFind(vector<int>& root, int a_set, int b_set) {
    while (root[a_set] != a_set) a_set = root[a_set];
    while (root[b_set] != b_set) b_set = root[b_set];
    if (root[a_set] != root[b_set]) root[b_set] = a_set;
  }
};
