/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Examples:
    // addTwoNumbers([1, 2, 3], [2, 3, 4]) -> [3, 5, 7]
    // addTwoNumbers([2, 5, 8], [1, 3, 9]) -> [3, 8, 7, 1]
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize dummy head node
        ListNode* dummyHead = new ListNode(0);
        // Create pointers p and q to heads of l1 and l2
        ListNode* p = l1;
        ListNode* q = l2;
        // and pointer to current node of new list
        ListNode* curr = dummyHead;

        // Set carry to intially 0
        int carry = 0;

        // Iterate through both l1 and l2 until p and q are null
        while (p != NULL || q != NULL) {
            // Set value of p to x, or 0 if p is null
            int x = (p != NULL) ? p->val : 0;
            // Set value of q to y, or 0 if q is null
            int y = (q != NULL) ? q->val : 0;

            // Set value of sum to x + y + previous carry
            int sum = x + y + carry;

            // Set value of carry to sum / 10
            carry = sum / 10;

            // Set value of current's next node to sum % 10
            curr->next = new ListNode(sum % 10);
            // Set current node to next node
            curr = curr->next;

            // Set p and q to their next nodes
            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
        }

        // If carry is greater than 0, set current's next to a new node
        // with value of carry
        if (carry > 0)
            curr->next = new ListNode(carry);

        // return dummy head's next node (first node of list)
        return dummyHead->next;
    }
};
