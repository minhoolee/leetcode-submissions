/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (48.09%)
 * Total Accepted:    385.6K
 * Total Submissions: 797.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 *
 *
 * Follow up:
 *
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
 *  Traverse list while adding nodes to stack
 *
 *  Time: O(n)
 *  Space: O(n)
 */

/**
 *  More space efficient approach
 *
 *  Swap nodes i and length-i (by value) until i >= length-i
 *
 *  Time: O(n^2)
 *  Space: O(1)
 */

/**
 *  Optimal iterative approach
 *
 *  Create new list that prepends next node in an insertion sort style
 *
 *  Time: O(n)
 *  Space: O(1)
 *
 *  reverseList(head):
 *    // First node becomes last node
 *    set tail to null
 *
 *    while head is not null
 *      set toAdd to head's next
 *      set head's next to tail
 *      set tail to head
 *      set head to toAdd
 *
 *    return tail
 *
 *  ListNode* reverseList(ListNode* head) {
 *    ListNode* tail = NULL;
 *
 *    while (head) {
 *      ListNode* toAdd = head->next;
 *      head->next = tail;
 *      tail = head;
 *      head = toAdd;
 *    }
 *
 *    return tail;
 *  }
 */

/**
 *  Optimal recursive approach
 *
 *  For every L[i], assume L[i+1..n] is reversed already
 *
 *  Time: O(n)
 *  Space: O(n) due to recursive call stack
 *
 *  reverseList(head):
 *    if head is null or head's next is null
 *      return head
 *    set newHead to reverseList(head's next)
 *    set head's next's next to head
 *    set head's next to null
 *    return newHead
 */

/**
 *  Test cases
 *
 *  NULL => NULL
 *  1->NULL => 1->NULL
 *  1->2->NULL => 2->1->NULL
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
  }
};
