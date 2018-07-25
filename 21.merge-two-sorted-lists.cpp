/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (42.23%)
 * Total Accepted:    377.7K
 * Total Submissions: 891.9K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
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
 *  Weave + concatenate
 *
 *  Time: O(n), where n is maximum length of the two lists
 *  Space: O(n)
 *
 *  Set p to l1 and q to l2
 *  Set pseudoHead to empty ListNode
 *  Set current to pseudoHead
 *  while p and q are not null
 *    If p's val >= q's val (select p by default)
 *      Set current's next to p
 *      Set p to p's next
 *    Else if q's val < p's val
 *      Set current's next to q
 *      Set q to q's next
 *    Set current to current's next
 *  Set current's next to the remainder of non-null p or q (concatenate step)
 *  Return pseudoHead's next
 */

/**
 * Test cases:
 * 1->2->5, 1->2->3 => 1->1->2->2->5->3
 * 1->2->5->6, 1->2->3 => 1->1->2->2->3->5->6
 * 1->2->3, 1->2->3 => 1->1->2->2->3->3
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p = l1;
    ListNode* q = l2;
    ListNode* pseudoHead = new ListNode(0);
    ListNode* current = pseudoHead;

    while (p != nullptr && q != nullptr) {
      if (p->val <= q->val) {
        current->next = p;
        p = p->next;
      } else if (q->val < p->val) {
        current->next = q;
        q = q->next;
      }
      current = current->next;
    }

    if (p != nullptr) current->next = p;
    else if (q != nullptr) current->next = q;

    return pseudoHead->next;
  }
};
