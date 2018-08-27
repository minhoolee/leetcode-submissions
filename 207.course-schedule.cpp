/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (34.60%)
 * Total Accepted:    142.4K
 * Total Submissions: 411.4K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 * Example 2:
 *
 *
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 *
 *
 * Note:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  DFS + Cycle Detection approach
 *
 *  DFS the adjacency list and mark each node as visited. Check for cycles
 *
 *  Time: O(n) aka O(V + E)
 *  Space: O(n) aka O(V + E)
 *
 *  canFinish(num_courses, prerequisites):
 *    set adj to empty map of empty set of integers
 *    for edge in prerequisites:
 *      insert edge[0] into adj[edge[1]]
 *
 *    // Visited saves three states:
 *    // -1: not visited
 *    //  0: visiting (can lead to cycle)
 *    //  1: visited (did not lead to cycle)
 *    set visited to array of integers, size num_courses, init to -1
 *
 *    for i, neighbors in adj:
 *      if not DFS(adj, visited, i):
 *        return false
 *
 *    return true
 *
 *  DFS(adj, visited, i):
 *    if visited[i] = 0:
 *      return false
 *    if visited[i] = 1:
 *      return true
 *
 *    set visited[i] to 0
 *
 *    for neighbor in adj[i]:
 *      if not DFS(adj, visited, neighbor):
 *        return false
 *
 *    set visited[i] to 1
 *    return true
 */

/**
 *  BFS / Kahn's Algorithm + Topological Sort / Cycle detection approach
 *
 *  Similar to 310: prune sources (cut outedges) and check if edges exist
 *  Sources have no more prerequisites. Cycles will never be pruned!
 *
 *  Time: O(V + E)
 *  Space: O(V + E)
 *
 *  canFinish(num_courses, prerequisites):
 *    set adj to empty map of empty set of integers
 *    set inedges to array of integers, size num_courses, init to 0
 *
 *    for edge in prerequisites:
 *      increment inedges[edge[0]]
 *      insert edge[0] into adj[edge[1]]
 *
 *    set sources to empty queue of integers
 *    for node, neighbors in adj:
 *      if inedges[node] = 0:
 *        add node to sources
 *
 *    set num_edges to prerequisites.length
 *
 *    while sources is not empty:
 *      set source to sources.front
 *      remove sources.front
 *      for neighbor in adj[source]:
 *        // Cut outedges of source
 *        decrement num_edges
 *        decrement inedges[neighbor]
 *        if inedges[neighbor] = 0:
 *          add neighbor to sources
 *
 *    if num_edges = 0:
 *      return true
 *    else:
 *      return false
 */

/**
 *  Test cases
 *
 *  3, [[1,0],[2,1],[0,2]] => false
 *  3, [[1,0],[1,2],[2,0]] => true
 *  3, [[1,0],[0,2]] => true
 */
class Solution {
 public:
  bool canFinish(int num_courses, const vector<pair<int, int>>& prerequisites) {
    if (num_courses <= 1 || prerequisites.empty()) return true;

    unordered_map<int, unordered_set<int>> adj;
    vector<int> inedges(num_courses, 0);

    for (const auto& edge : prerequisites) {
      ++inedges[edge.first];
      adj[edge.second].insert(edge.first);
    }

    queue<int> sources;
    for (const auto& entry : adj) {
      const int node = entry.first;
      if (inedges[node] == 0) {
        sources.push(node);
      }
    }

    int num_edges = prerequisites.size();

    while (!sources.empty()) {
      int source = sources.front(); sources.pop();

      for (const auto& neighbor : adj[source]) {
        --num_edges;

        if (--inedges[neighbor] == 0) {
          sources.push(neighbor);
        }
      }
    }

    return num_edges == 0;
  }
};
