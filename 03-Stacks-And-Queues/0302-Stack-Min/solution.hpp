#ifndef STACK_MIN_20210222
#define STACK_MIN_20210222

#include <stack>

/**
 * How would you design a stack which, in addition to push and pop, has a function
 * `min` which returns the minimum element?. `push`, `pop` and `min` should all work
 * in `O(1)` time.
 */
class StackWithMin {
public:
    void push(int value);
    void pop();
    int min();

private:
    std::stack<int> m_values;
    std::stack<int> m_mins;
};

#endif