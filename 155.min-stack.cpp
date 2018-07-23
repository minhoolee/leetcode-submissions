/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (32.24%)
 * Total Accepted:    203.3K
 * Total Submissions: 629.3K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 *
 *
 * pop() -- Removes the element on top of the stack.
 *
 *
 * top() -- Get the top element.
 *
 *
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 *
 * Example:
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 *
 */

static auto x = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return nullptr;
}();

/**
 *  First approach
 *
 *  Stack + Min Heap
 *
 *  Time:
 *    push: O(logn)
 *    pop: O(logn)
 *    top: O(1)
 *    getMin:O(1)
 *  Space: O(n)
 */

/**
 *  Better approach
 *
 *  Stack + double push & double pop
 *
 *  Time:
 *    push: O(1)
 *    pop: O(1)
 *    top: O(1)
 *    getMin: O(1)
 *  Space: O(n)
 *
 *  MinStack()
 *    Set s to new empty stack
 *    Set min to INT_MAX
 *
 *  void push(int x)
 *    If x <= min
 *      Push min to stack (double push to save prev min)
 *      Set min to x
 *    Push x to stack
 *
 *  void pop()
 *    Throw logic error if empty
 *    If stack's top == min
 *      Pop stack
 *      Set min to stack's top
 *    Pop stack
 *
 *  int top()
 *    Throw logic error if empty
 *    Return stack's top
 *
 *  int getMin()
 *    Throw logic error if empty
 *    Return min
 */

/**
 * Test cases
 *
 * push(0)
 * getMin() -> 0
 * push(-2)
 * push(-1)
 * top() -> -1
 * getMin() -> -2
 * pop()
 * getMin() -> -2
 * pop()
 * getMin() -> 0
 * pop()
 */

class MinStack {
 public:
  MinStack() {
    min = INT_MAX;
  }

  void push(int x) {
    if (s.empty()) s.push(x); // Double push first value (always min)
    if (x <= min) {
      s.push(min);
      min = x;
    }
    s.push(x);
  }

  void pop() {
    if (s.empty()) throw std::logic_error("Precondition: non-empty stack");
    if (s.top() == min) {
      s.pop();
      min = s.top(); // Previous min that was saved with double push
    }
    s.pop();
  }

  int top() {
    if (s.empty()) throw std::logic_error("Precondition: non-empty stack");
    return s.top();
  }

  int getMin() {
    if (s.empty()) throw std::logic_error("Precondition: non-empty stack");
    return min;
  }

 private:
  int min;
  stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
