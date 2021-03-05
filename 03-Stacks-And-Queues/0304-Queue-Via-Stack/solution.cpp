#include "solution.hpp"

int MyQueue::size()
{
    return m_newest.size() + m_oldest.size();
}

void MyQueue::add(int i)
{
    m_newest.push(i);
}

/**
 * For simplicity, assume caller will ensure the queue is not empty 
 */
int MyQueue::peek()
{
    shift_stack();
    return m_oldest.top();
}

int MyQueue::remove()
{
    shift_stack();
    int top = m_oldest.top();
    m_oldest.pop();
    return top;
}

// ======================
// IMPLEMENTATION HELPERS
// ======================
void MyQueue::shift_stack()
{
    if (m_oldest.empty()) {
        while (!m_newest.empty()) {
            int top = m_newest.top();
            m_newest.pop();
            m_oldest.push(top);
        }
    }
}