/*
 * [871] Keys and Rooms
 *
 * https://leetcode.com/problems/keys-and-rooms/description/
 *
 * algorithms
 * Medium (56.80%)
 * Total Accepted:    11.8K
 * Total Submissions: 20.7K
 * Testcase Example:  '[[1],[2],[3],[]]'
 *
 * There are N rooms and you start in room 0.  Each room has a distinct number
 * in 0, 1, 2, ..., N-1, and each room may have some keys to access the next
 * room. 
 *
 * Formally, each room i has a list of keys rooms[i], and each key rooms[i][j]
 * is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j]
 * = v opens the room with number v.
 *
 * Initially, all the rooms start locked (except for room 0). 
 *
 * You can walk back and forth between rooms freely.
 *
 * Return true if and only if you can enter every room.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [[1],[2],[3],[]]
 * Output: true
 * Explanation:
 * We start in room 0, and pick up key 1.
 * We then go to room 1, and pick up key 2.
 * We then go to room 2, and pick up key 3.
 * We then go to room 3.  Since we were able to go to every room, we return
 * true.
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,3],[3,0,1],[2],[0]]
 * Output: false
 * Explanation: We can't enter the room with number 2.
 *
 *
 * Note:
 *
 *
 * 1 <= rooms.length <= 1000
 * 0 <= rooms[i].length <= 1000
 * The number of keys in all rooms combined is at most 3000.
 *
 *
 */

/**
 *  Notes for improvement
 *
 *  Instead of iterating through visited vector, keep a running counter
 *  of num_vertices and check with number of vertices. This is slightly
 *  cleaner with iterative version
 */

/**
 *  DFS Recursive approach
 *
 *  DFS while marking node as visited
 *
 *  Time: O(V + E)
 *  Space: O(V)
 *
 *  canVisitAllRooms(rooms):
 *    set n to rooms.size
 *    set visited as array of booleans, size n, init to false
 *
 *    // Start with room 0 only
 *    DFS(rooms, visited, 0)
 *
 *    for open_room in visited:
 *      if not open_room:
 *        return false
 *
 *    return true
 *
 *  DFS(rooms, visited, i):
 *    if visited[i]:
 *      return
 *
 *    set visited[i] to true
 *
 *    for next_room in rooms[i]:
 *      DFS(rooms, visited, next_room)
 */

/**
 *  DFS Iterative approach
 *
 *  DFS while marking node as visited
 *
 *  Time: O(V + E)
 *  Space: O(V)
 *
 *  canVisitAllRooms(rooms):
 *    set n to rooms.size
 *    set visited as array of booleans, size n, init to false
 *    set visited[0] to true
 *
 *    set stack to stack of integers
 *    add 0 to stack
 *
 *    while stack is not empty:
 *      set i to stack.top
 *      remove stack.top
 *
 *      for next_room in rooms[i]:
 *        if not visited[next_room]:
 *          set visited[next_room] to true
 *          add next_room to stack
 *
 *    for open_room in visited:
 *      if not open_room:
 *        return false
 *
 *    return true
 */
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    visited[0] = true;
    int num_visited = 1;

    stack<int> next_rooms;
    next_rooms.push(0);

    while (!next_rooms.empty()) {
      int i = next_rooms.top(); next_rooms.pop();

      // Visit next rooms with key from room i
      for (const auto& next_room : rooms[i]) {
        if (!visited[next_room]) {
          visited[next_room] = true;
          ++num_visited;
          next_rooms.push(next_room);
        }
      }
    }

    return num_visited == n;
  }
};
