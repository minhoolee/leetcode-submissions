/*
 * [310] Minimum Height Trees
 *
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (29.09%)
 * Total Accepted:    49.2K
 * Total Submissions: 169.1K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * For a undirected graph with tree characteristics, we can choose any node as
 * the root. The result graph is then a rooted tree. Among all possible rooted
 * trees, those with minimum height are called minimum height trees (MHTs).
 * Given such a graph, write a function to find all the MHTs and return a list
 * of their root labels.
 *
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be
 * given the number n and a list of undirected edges (each edge is a pair of
 * labels).
 *
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges.
 *
 * Example 1 :
 *
 *
 * Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 *
 * ⁠       0
 * ⁠       |
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 *
 * Output: [1]
 *
 *
 * Example 2 :
 *
 *
 * Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 *
 * ⁠    0  1  2
 * ⁠     \ | /
 * ⁠       3
 * ⁠       |
 * ⁠       4
 * ⁠       |
 * ⁠       5
 *
 * Output: [3, 4]
 *
 * Noteus
 *
 *
 *
 * According to the definition of tree on Wikipedia: “a tree is an undirected
 * graph in which any two vertices are connected by exactly one path. In other
 * words, any connected graph without simple cycles is a tree.”
 * The height of a rooted tree is the number of edges on the longest downward
 * path between the root and a leaf.
 *
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  BFS approach
 *
 *  Keep pruning leaves until either 1 or 2 nodes remain
 *
 *  Key concept is that MHT root will be in the middle of the longest
 *  (acyclic) path through the tree. This guarentees that the path
 *  from root to either end of the longest path will be the shortest
 *
 *  Time: O(n)
 *  Space: O(n)
 *
 *  findMinHeightTrees(n, edges):
 *    // Build adjacency list
 *    set adj to empty map of empty hash sets of integers
 *    for edge in edges:
 *      insert edge[1] into adj[edge[0]]
 *      insert edge[0] into adj[edge[1]]
 *
 *    // Build initial list of leaves
 *    set leaves to empty list of integers
 *    for neighbors in adj:
 *      if neighbors.val.size = 1:
 *        add neighbors.key to leaves
 *
 *    // Prune leaves and then add new leaves until 1 or 2 nodes remain
 *    while n > 2:
 *      n -= leaves.size
 *      set new_leaves to empty list of integers
 *
 *      for leaf in leaves:
 *        set next_node to adj[leaf]
 *        remove adj[next_node][leaf]
 *        if adj[next_node].size = 1:
 *          add next_node to new_leaves
 *
 *      set leaves to new_leaves
 *
 *    return leaves
 */
class Solution {
 private:
  struct Node {
    unordered_set<int> neighbors;
    int degree() const { return neighbors.size(); }
  };

 public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    if (n <= 1) return {0};

    unordered_map<int, Node> nodes;
    for (const auto& edge : edges) {
      nodes[edge.second].neighbors.insert(edge.first);
      nodes[edge.first].neighbors.insert(edge.second);
    }

    vector<int> leaves;
    for (const auto& entry : nodes) {
      const Node* node = &entry.second;
      const int val = entry.first;
      if (node->degree() == 1) leaves.push_back(val);
    }

    while (n > 2) {
      n -= leaves.size();
      vector<int> new_leaves;

      for (const auto& leaf : leaves) {
        int next_node = *(nodes[leaf].neighbors.begin());
        nodes[next_node].neighbors.erase(leaf);
        if (nodes[next_node].degree() == 1) new_leaves.push_back(next_node);
      }

      leaves = new_leaves;
    }

    return leaves;
  }
};
