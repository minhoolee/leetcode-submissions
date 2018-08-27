/*
 * [859] Design Circular Deque
 *
 * https://leetcode.com/problems/design-circular-deque/description/
 *
 * algorithms
 * Medium (48.90%)
 * Total Accepted:    1.3K
 * Total Submissions: 2.6K
 * Testcase Example:
 * '["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]\n[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * Design your implementation of the circular double-ended queue (deque).
 *
 * Your implementation should support following operations:
 *
 *
 * MyCircularDeque(k): Constructor, set the size of the deque to be k.
 * insertFront(): Adds an item at the front of Deque. Return true if the
 * operation is successful.
 * insertLast(): Adds an item at the rear of Deque. Return true if the
 * operation is successful.
 * deleteFront(): Deletes an item from the front of Deque. Return true if the
 * operation is successful.
 * deleteLast(): Deletes an item from the rear of Deque. Return true if the
 * operation is successful.
 * getFront(): Gets the front item from the Deque. If the deque is empty,
 * return -1.
 * getRear(): Gets the last item from Deque. If the deque is empty, return
 * -1.
 * isEmpty(): Checks whether Deque is empty or not. 
 * isFull(): Checks whether Deque is full or not.
 *
 *
 *
 *
 * Example:
 *
 *
 * MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to
 * be 3
 * circularDeque.insertLast(1);            // return true
 * circularDeque.insertLast(2);            // return true
 * circularDeque.insertFront(3);            // return true
 * circularDeque.insertFront(4);            // return false, the queue is full
 * circularDeque.getRear();              // return 32
 * circularDeque.isFull();                // return true
 * circularDeque.deleteLast();            // return true
 * circularDeque.insertFront(4);            // return true
 * circularDeque.getFront();            // return 4
 *
 *
 *
 *
 * Note:
 *
 *
 * All values will be in the range of [0, 1000].
 * The number of operations will be in the range of [1, 1000].
 * Please do not use the built-in Deque library.
 *
 *
 */
class MyCircularDeque {
 private:
  int front_;
  int back_;
  int size_;
  int capacity_;
  vector<int> queue_;

 public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k);

  /** Adds an item at the front of Deque. Return true if the operation is
   * successful. */
  bool insertFront(int value);

  /** Adds an item at the rear of Deque. Return true if the operation is
   * successful. */
  bool insertLast(int value);

  /** Deletes an item from the front of Deque. Return true if the operation is
   * successful. */
  bool deleteFront();

  /** Deletes an item from the rear of Deque. Return true if the operation is
   * successful. */
  bool deleteLast();

  /** Get the front item from the deque. */
  int getFront();

  /** Get the last item from the deque. */
  int getRear();

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty();

  /** Checks whether the circular deque is full or not. */
  bool isFull();
};

/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque::MyCircularDeque(int k)
    : front_(0), back_(k - 1), size_(0), capacity_(k), queue_(k, 0) {}

/** Adds an item at the front of Deque. Return true if the operation is
 * successful. */
bool MyCircularDeque::insertFront(int value) {
  if (isFull()) return false;

  // Decrement front, wrapping if necessary
  front_ = (front_ - 1 + capacity_) % capacity_;
  queue_[front_] = value;
  ++size_;

  return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is
 * successful. */
bool MyCircularDeque::insertLast(int value) {
  if (isFull()) return false;

  // Increment back, wrapping if necessary
  back_ = (back_ + 1) % capacity_;
  queue_[back_] = value;
  ++size_;

  return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is
 * successful. */
bool MyCircularDeque::deleteFront() {
  if (isEmpty()) return false;
  front_ = (front_ + 1) % capacity_;
  --size_;
  return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is
 * successful. */
bool MyCircularDeque::deleteLast() {
  if (isEmpty()) return false;
  back_ = (back_ - 1 + capacity_) % capacity_;
  --size_;
  return true;
}

/** Get the front item from the deque. */
int MyCircularDeque::getFront() {
  if (isEmpty()) return -1;
  return queue_[front_];
}

/** Get the last item from the deque. */
int MyCircularDeque::getRear() {
  if (isEmpty()) return -1;
  return queue_[back_];
}

/** Checks whether the circular deque is empty or not. */
bool MyCircularDeque::isEmpty() { return size_ == 0; }

/** Checks whether the circular deque is full or not. */
bool MyCircularDeque::isFull() { return size_ == capacity_; }

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
