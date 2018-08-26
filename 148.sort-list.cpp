/*
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (31.34%)
 * Total Accepted:    145.7K
 * Total Submissions: 464.2K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * Example 1:
 *
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 *
 *
 * Example 2:
 *
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
 *  Notes for improvement
 *
 *  I'd say the most valuable part of this problem is learning how to cut
 *  a linked list in half (mid = ceiling of half) using two pointers.
 *  Using a unique_ptr for pseudo_head is also cool too, I guess.
 */

/**
 *  Merge sort + two pointer approach
 *
 *  Merge sort and use two pointer to find mid point of each list
 *
 *  sortList(head):
 *    // Base case: 0 or 1 node list
 *    if head is null or head.next is null:
 *      return head
 *
 *    set mid to SplitList(head)
 *
 *    set l1 to MergeSort(head)
 *    set l2 to MergeSort(mid)
 *
 *    return Merge(l1, l2)
 *
 *  SplitList(head):
 *    set prev to null
 *    set slow to head
 *    set fast to head
 *
 *    while fast.next != null:
 *      set prev to slow
 *      set slow to slow.next
 *      set fast to fast.next.next
 *
 *    set prev.next to null
 *
 *    return slow
 *
 *  Merge(low, mid):
 *    set pseudo_head to ListNode of val 0
 *    set curr to pseudo_head
 *
 *    while low != null && mid != null:
 *      if mid.val < low.val:
 *        set curr.next to mid
 *        set mid to mid.next
 *      else:
 *        set curr.next to low
 *        set low to low.next
 *      set curr to curr.next
 *
 *    if low != null:
 *      set curr.next to low
 *
 *    if mid != null:
 *      set curr.next to mid
 *
 *    return pseudo_head.next
 */
class Solution {
 private:
  ListNode* SplitList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    prev->next = NULL;

    return slow;
  }

  ListNode* Merge(ListNode* low, ListNode* mid) {
    // auto pseudo_head = std::make_unique<ListNode>(0);
    // ListNode* curr = pseudo_head.get();
    ListNode pseudo_head(0);
    ListNode* curr = &pseudo_head;

    while (low != NULL && mid != NULL) {
      if (mid->val < low->val) {
        curr->next = mid;
        mid = mid->next;
      } else {
        curr->next = low;
        low = low->next;
      }
      curr = curr->next;
    }

    if (low) curr->next = low;
    if (mid) curr->next = mid;

    /* return pseudo_head->next; */
    return pseudo_head.next;
  }

 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* mid = SplitList(head);

    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(mid);

    return Merge(l1, l2);
  }
};
