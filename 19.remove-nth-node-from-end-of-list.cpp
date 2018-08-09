/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.78%)
 * Total Accepted:    274.9K
 * Total Submissions: 813.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 *
 * Example:
 *
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 *
 *
 * Note:
 *
 * Given n will always be valid.
 *
 * Follow up:
 *
 * Could you do this in one pass?
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
 *  Length double-pass approach
 *
 *  Traverse list to find length and then traverse list until n
 *
 *  Time: O(n)
 *  Space: O(1)
 */

/**
 *  Hash table single-pass approach
 *
 *  Create hash table storing index to node and calculate length - n
 *
 *  Time: O(n)
 *  Space: O(n)
 */

/**
 *  Reverse double-pass approach
 *
 *  Reverse list and traverse until n and reverse list again
 *
 *  Time: O(n)
 *  Space: O(1)
 */

/**
 *  Stack single-pass approach
 *
 *  Push nodes onto stack and pop stack n times
 *
 *  Time: O(n)
 *  Space: O(n)
 */

/**
 *  Two pointer single-pass approach
 *
 *  Slow pointer lags n steps behind fast pointer until last node
 *
 *  Time: O(n)
 *  Space: O(1)
 *
 *  removeNthFromEnd(head, n):
 *    // Take care of some edge cases, unsure of what to do if n < 1
 *    if head is null or if head's next is null or n < 1
 *      return null
 *
 *    set slow to head
 *    set fast to head
 *
 *    // Counter to fast's index (1 based index)
 *    set i to 1
 *
 *    // Loop until fast reaches last node
 *    while fast's next is not null
 *      set fast to fast's next
 *      increment i
 *
 *      // Slow pointer lags by n+1 in order to delete nth node
 *      if i > n+1
 *        set slow to slow's next
 *
 *    // After loop, i (index of fast) is length of list
 *    // If n equals length of list, node to delete is head
 *    if i equals n
 *      return head's next
 *
 *    set slow's next to slow's next's next
 *
 *    return head
 */

/**
 *  Test cases
 *
 *  1->2->null; n=1 => 1->null
 *  1->2->null; n=2 => 2->null
 *  1->2->3->null; n=3 => 2->3->null
 *  1->2->3->null; n=2 => 1->3->null
 *  1->2->3->null; n=1 => 1->2->null
 */
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head || !head->next || n < 1) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;
    int i = 1;

    while (fast->next) {
      fast = fast->next;
      ++i;
      if (i > n + 1) slow = slow->next;
    }

    if (i == n) return head->next;
    slow->next = slow->next->next;

    return head;
  }
};
