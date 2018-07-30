/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (40.60%)
 * Total Accepted:    251.6K
 * Total Submissions: 618.8K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * Example 1:
 *
 *
 * Input: 1->1->2
 * Output: 1->2
 *
 *
 * Example 2:
 *
 *
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
 *  Loop to skip duplicates
 *
 *  Time: O(n)
 *  Space: O(1)
 *
 *  deleteDuplicates(head):
 *    Set curr to head
 *    While curr is not null
 *      Set dup to curr's next
 *
 *      // Find next unique node
 *      While dup is not null and curr's val is equal to dup's val
 *        Set dup to dup's next
 *
 *      Set curr's next to dup
 *      Set curr to curr's next
 *
 *    Return head
 */

/**
 *  Test cases
 *
 *  NULL => NULL
 *  1->2->3->NULL => 1->2->3->NULL
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;

    while (curr) {
      ListNode* dup = curr->next;

      while (dup && curr->val == dup->val) dup = dup->next;

      curr->next = dup;
      curr = curr->next;
    }

    return head;
  }
};
