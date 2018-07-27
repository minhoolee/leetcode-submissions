/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (34.84%)
 * Total Accepted:    276.9K
 * Total Submissions: 795.2K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  First approach
 *
 *  Floyd cycle (two pointer)
 *
 *  Time: O(n)
 *  Space: O(1)
 *
 *  Set slow and fast to head
 *  While slow and fast are not null
 *    If fast's next is null, return false
 *
 *    Set slow to slow's next
 *    Set fast to fast's next's next
 *
 *    If slow equals fast, return true
 *  Return false
 */

/**
 *  Test cases:
 *  null ->  => false
 *  1 -> 2 -> => false
 *  1 -> 2 -> 3 -> list[0] => true
 *  1 -> 2 -> 3 -> list[2] => true
 */
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = slow;

    while (slow && fast) {
      if (!fast->next) return false;

      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) return true;
    }
    return false;
  }
};
