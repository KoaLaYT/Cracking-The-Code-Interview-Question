#include "solution.hpp"

int pop_and_get(std::stack<int>& stack);

void sort_stack(std::stack<int>& stack)
{
    std::stack<int> temp;

    while (!stack.empty()) {
        int top = pop_and_get(stack);

        while (!temp.empty() && temp.top() > top) {
            int t = pop_and_get(temp);
            stack.push(t);
        }
        temp.push(top);
    }

    while (!temp.empty()) {
        int top = pop_and_get(temp);
        stack.push(top);
    }
}

// ======================
// IMPLEMENTATION HELPERS
// ======================
int pop_and_get(std::stack<int>& stack)
{
    int top = stack.top();
    stack.pop();
    return top;
}