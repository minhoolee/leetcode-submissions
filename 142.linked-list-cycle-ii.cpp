/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (30.19%)
 * Total Accepted:    159.3K
 * Total Submissions: 528K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * 
 * 
 * Note: Do not modify the linked list.
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
 *  findCycle(head, intersect)
 *    Set forward to head
 *    Set backward to intersect
 *
 *    While forward does not equal backward
 *      Set forward to forward's next
 *      Set backward to backwards->next
 *    Return forward
 *
 *  detectCycle(head)
 *    Set slow and fast to head
 *    While fast and fast's next are not null
 *      Set slow to slow's next
 *      Set fast to fast's next's next
 *
 *      If slow equals fast return findCycle(head, slow)
 *    Return null
 */

/**
 *  Test cases:
 *  null ->  => null
 *  1 -> 2 -> => null
 *  1 -> 2 -> 3 -> list[0] => 1
 *  1 -> 2 -> 3 -> list[2] => 3
 */
class Solution {
 private:
  // Precondition: loop has cycle, head points to start of loop, and 
  // intersect points to node where slow and fast pointer met
  ListNode* findCycle(ListNode* head, ListNode* intersect) {
    ListNode* forward = head;
    ListNode* backward = intersect;

    while (forward != backward) {
      // Precondition is not met
      if (!forward || !backward) return nullptr;

      forward = forward->next;
      backward = backward->next;
    }

    return forward;
  }

 public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = slow;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast)
        return findCycle(head, slow);
    }

    return nullptr;
  }
};
