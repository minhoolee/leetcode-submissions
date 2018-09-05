/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (26.91%)
 * Total Accepted:    123.4K
 * Total Submissions: 458.3K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * Corner Cases:
 *
 *
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
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
 *  Using a set to check multiple values of input is super clean. Key to this
 *  problem is realizing you need a stack and then realizing that you need to
 *  process the stack in reverse (FIFO)
 */

/**
 *  Deque
 *
 *  Stack to push non "..", ".", or "" directories, pop to remove if ".."
 *  Process stack like a queue in order to build final path; use deque instead
 *
 *  Time: O(n)
 *  Space: O(n)
 */
class Solution {
 public:
  string simplifyPath(string path) {
    if (path.empty()) return "";

    deque<string> dirs;
    unordered_set<string> skip = {"..", ".", ""};

    string dir;
    stringstream paths(path);
    while (getline(paths, dir, '/')) {
      if (skip.find(dir) == skip.end()) dirs.push_back(dir);
      else if (dir == ".." && !dirs.empty()) dirs.pop_back();
    }

    string res;
    for (const auto& d : dirs) {
      res += "/" + d;
    }

    return !res.empty() ? res : "/";
  }
};
