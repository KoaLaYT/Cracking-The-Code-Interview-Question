#include "solution.hpp"

void SetOfStacks::push(int value)
{
    for (auto& s : m_stacks) {
        if (s.size() < m_capacity) {
            return s.push(value);
        }
    }
    // empty or previous stack all full
    std::stack<int> s;
    s.push(value);
    return m_stacks.push_back(s);
}

int SetOfStacks::pop()
{
    auto it = m_stacks.end();
    std::advance(it, -1);
    return pop_at(it);
}

int SetOfStacks::pop_at(int index)
{
    auto it = m_stacks.begin();
    std::advance(it, index);
    return pop_at(it);
}

// ======================
// IMPLEMENTATION HELPERS
// ======================
int SetOfStacks::pop_at(std::vector<std::stack<int>>::iterator it)
{
    int top = it->top();
    it->pop();
    if (it->empty()) m_stacks.erase(it);
    return top;
}