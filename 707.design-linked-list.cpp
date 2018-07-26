/*
 * [838] Design Linked List
 *
 * https://leetcode.com/problems/design-linked-list/description/
 *
 * algorithms
 * Easy (3.99%)
 * Total Accepted:    1.8K
 * Total Submissions: 19.6K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * Design your implementation of the linked list. You can choose to use the
 * singly linked list or the doubly linked list. A node in a singly linked list
 * should have two attributes: val and next. val is the value of the current
 * node, and next is a pointer/reference to the next node. If you want to use
 * the doubly linked list, you will need one more attribute prev to indicate
 * the previous node in the linked list. Assume all nodes in the linked list
 * are 0-indexed.
 *
 * Implement these functions in your linked list class:
 *
 *
 * get(index) : Get the value of the index-th node in the linked list. If the
 * index is invalid, return -1.
 * addAtHead(val) : Add a node of value val before the first element of the
 * linked list. After the insertion, the new node will be the first node of the
 * linked list.
 * addAtTail(val) : Append a node of value val to the last element of the
 * linked list.
 * addAtIndex(index, val) : Add a node of value val before the index-th node in
 * the linked list. If index equals to the length of linked list, the node will
 * be appended to the end of linked list. If index is greater than the length,
 * the node will not be inserted.
 * deleteAtIndex(index) : Delete the index-th node in the linked list, if the
 * index is valid.
 *
 *
 * Example:
 *
 *
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
 * linkedList.get(1);            // returns 2
 * linkedList.deleteAtIndex(1);  // now the linked list is 1->3
 * linkedList.get(1);            // returns 3
 *
 *
 * Note:
 *
 *
 * All values will be in the range of [1, 1000].
 * The number of operations will be in the range of [1, 1000].
 * Please do not use the built-in LinkedList library.
 *
 */

static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

/**
 *  Test cases:
 *  get(0) => -1
 *  addAtHead(5) => 5 ->
 *  addAtTail(2) => 5 -> 2 ->
 *  addAtIndex(2, 3) => 5 -> 2 -> 3 ->
 *  addAtIndex(1, 4) => 5 -> 4 -> 2 -> 3 ->
 *  get(2) => 2
 *  get(4) => -1
 *  deleteAtIndex(0) => 4 -> 2 -> 3 ->
 *  get(2) => 3
 *  deleteAtIndex(1) => 4 -> 3 ->
 *  get(1) => 3
 *  deleteAtIndex(2) => 4 -> 3 ->
 *  get(1) => 3
 */
class MyLinkedList {
 private:
   class Node {
    public:
     int val;
     Node* next;

     Node() = default;
     Node(int val, Node* next) : val(val), next(next) {}
   };

   Node* head;

 public:
  /** Initialize your data structure here. */
  MyLinkedList() : head (nullptr) {}

  /**
   * Get the value of the index-th node in the linked list.
   * If the index is invalid, return -1.
   */
  int get(int index) {
    Node* curr = head;
    if (!head) return -1;
    for (int i = 0; i < index; ++i) {
      curr = curr->next;
      if (!curr) return -1;
    }
    return curr->val;
  }

  /**
   * Add a node of value val before the first element of the linked list.
   * After the insertion, the new node will be the first node of the
   * linked list.
   */
  void addAtHead(int val) {
    Node* newNode  = new Node(val, head);
    head = newNode;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    Node* curr = head;
    if (!head) {
      head = new Node(val, nullptr);
      return;
    }

    while (curr->next) {
      curr = curr->next;
    }
    curr->next = new Node(val, nullptr);
  }

  /**
   * Add a node of value val before the index-th node in the linked list.
   * If index equals to the length of linked list, the node will be
   * appended to the end of linked list. If index is greater than the length,
   * the node will not be inserted.
   */
  void addAtIndex(int index, int val) {
    Node* curr = head;
    if (!head) {
      if (index == 0) head = new Node(val, nullptr);
      return;
    }

    for (int i = 0; i < index-1; ++i) {
      // Don't insert when index is greater than length
      if (!curr) return;
      curr = curr->next;
    }
    // Insert (or append) node at index
    curr->next = new Node(val, curr->next);
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    Node* curr = head;
    if (!head) return;
    for (int i = 0; i < index-1; ++i) {
      curr = curr->next;
      // Reached end of list before index
      if (!curr->next) return;
    }
    // Index-th node does not exist
    if (!curr->next) return;

    // Delete index-th node by either skipping it or setting it to nullptr
    if (curr->next->next)
      curr->next = curr->next->next;
    else 
      curr->next = nullptr;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
