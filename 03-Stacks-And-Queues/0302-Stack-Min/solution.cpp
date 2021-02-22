#include "solution.hpp"

void StackWithMin::push(int value)
{
    m_values.push(value);
    if (m_mins.empty() || value <= min()) {
        m_mins.push(value);
    }
}

void StackWithMin::pop()
{
    int top = m_values.top();
    m_values.pop();
    if (top == min()) {
        m_mins.pop();
    }
}

int StackWithMin::min() { return m_mins.top(); }