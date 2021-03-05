#ifndef QUEUE_VIA_STACK_20210305
#define QUEUE_VIA_STACK_20210305

#include <stack>

/**
 * Implement a MyQueue class which implements a queue with two stacks.
 */
class MyQueue {
public:
    int size();
    void add(int i);
    int peek();
    int remove();

private:
    std::stack<int> m_newest;
    std::stack<int> m_oldest;

    void shift_stack();
};

#endif