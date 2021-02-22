#ifndef STACK_OF_PLATES_20210222
#define STACK_OF_PLATES_20210222

#include <stack>
#include <vector>

/**
 * Imagine a literal stack of plates. If the stack gets too high, it might topple.
 * Therefore, in real life, we would likely  start a new stack when previous stack 
 * exceeds some threhold. Implement a data structure `SetOfStacks` that mimics this.
 * `SetOfStacks` should be composed of several stacks and should create a new stack
 * once the previous one exceeds capacity. `SetOfStacks.push()` and `SetOfStacks.pop()`
 * should behave identically to a single stack.
 * 
 * FOLLOW UP:
 * 
 * Implement a function `popAt(int index)` which perform a pop operation on a specific
 * substack.
 */
class SetOfStacks {
public:
    explicit SetOfStacks(int cap) : m_capacity{cap} {}

    void push(int value);

    int pop();

    bool empty() { return m_stacks.empty(); }

    int num() { return m_stacks.size(); }

    int pop_at(int index);

private:
    int m_capacity;
    std::vector<std::stack<int>> m_stacks;

    int pop_at(std::vector<std::stack<int>>::iterator it);
};

#endif