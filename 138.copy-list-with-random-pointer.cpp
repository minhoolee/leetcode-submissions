/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.72%)
 * Total Accepted:    167.1K
 * Total Submissions: 649.6K
 * Testcase Example:  '{}'
 *
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 *
 *
 * Return a deep copy of the list.
 *
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

/**
 *  Optimal approach
 *
 *  Weave deep copies and then extract them
 *
 *  Time: O(n)
 *  Space: O(n)
 *
 *  copyRandomList(head):
 *    Set curr to head
 *
 *    // Weave deep copies
 *    While curr is not null
 *      Set copy to new node with curr's val
 *      Set copy's next to curr's next
 *      Set curr's next to copy
 *      Set curr to copy's next
 *
 *    Set curr to head
 *
 *    // Set deep copies' randoms (must be done after weaving)
 *    While curr is not null
 *      Set curr's next's (copy) random to curr's random's next (copy random)
 *      Set curr to curr's next's next
 *
 *    Set curr to head
 *    Set pseudoHead to new node of value 0
 *    Set copyCurr to psuedoHead
 *
 *    // Extract copies from original list
 *    While curr is not null
 *      Set copyCurr's next to curr's next
 *      Set curr's next to curr's next's next // Remove copy
 *      Set copyCurr to copyCurr's next
 *      Set curr to curr's next
 *
 *    Return pseudoHead's next;
 */
class Solution {
 public:
  RandomListNode* copyRandomList(RandomListNode* head) {
    RandomListNode* curr = head;

    // Weave deep copies
    while (curr) {
      RandomListNode* copy = new RandomListNode(curr->label);
      copy->next = curr->next;
      curr->next = copy;
      curr = curr->next->next;
    }

    curr = head;

    // Set deep copies' randoms (must be done after weaving)
    while (curr) {
      if (curr->random)
        curr->next->random = curr->random->next;
      else
        curr->next->random = NULL;
      curr = curr->next->next;
    }

    curr = head;
    RandomListNode* pseudoHead = new RandomListNode(0);
    RandomListNode* copyCurr = pseudoHead;

    // Extract copies from original list
    while (curr) {
      copyCurr->next = curr->next;
      curr->next = curr->next->next;  // Remove copy
      copyCurr = copyCurr->next;
      curr = curr->next;
    }

    return pseudoHead->next;
  }
};
