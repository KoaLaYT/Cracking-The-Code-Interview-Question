#include "solution.hpp"

#include <cassert>

MultiStack::MultiStack(int init_size)
{
    m_values = std::vector<int>(init_size * STACK_NUM);
    m_stack_infos = std::vector<StackInfo>(STACK_NUM);
    for (int i = 0; i < STACK_NUM; ++i) {
        m_stack_infos[i].start = i * init_size;
        m_stack_infos[i].capacity = init_size;
        m_stack_infos[i].size = 0;
    }
}

void MultiStack::push(int stack_num, int value)
{
    // For simplicity, assume the caller will ensure the stack is not full.
    assert(!is_all_full());

    if (is_full(stack_num)) {
        expand(stack_num);
    }

    m_values[next_idx(stack_num)] = value;
    m_stack_infos[stack_num].size += 1;
}

int MultiStack::pop(int stack_num)
{
    // For simplicity, assume the caller will ensure the stack is not empty.
    assert(!is_empty(stack_num));

    int top = peek(stack_num);
    m_stack_infos[stack_num].size -= 1;
    return top;
}

int MultiStack::peek(int stack_num)
{
    int top = wrapped_index(next_idx(stack_num) - 1 + m_values.size());
    return m_values[top];
}

bool MultiStack::is_empty(int stack_num)
{
    return m_stack_infos[stack_num].is_empty();
}

bool MultiStack::is_full(int stack_num)
{
    return m_stack_infos[stack_num].is_full();
}

bool MultiStack::is_all_full()
{
    int total_size = 0;
    for (const auto& info : m_stack_infos) {
        total_size += info.size;
    }
    return total_size == STACK_NUM * m_stack_infos.size();
}

// ======================
// IMPLEMENTATION HELPERS
// ======================
int MultiStack::next_idx(int stack_num)
{
    StackInfo& info = m_stack_infos[stack_num];
    return wrapped_index(info.start + info.size);
}

// For simplicity, the expand strategy is shift the next stack by 1
void MultiStack::expand(int stack_num)
{
    shift((stack_num + 1) % STACK_NUM);
    m_stack_infos[stack_num].capacity += 1;
}

void MultiStack::shift(int stack_num)
{
    if (m_stack_infos[stack_num].is_full()) {
        return shift((stack_num + 1) % STACK_NUM);
    }

    StackInfo& info = m_stack_infos[stack_num];
    for (int i = 0; i < info.size; ++i) {
        m_values[wrapped_index(i + info.start + 1)] = m_values[wrapped_index(i + info.start)];
    }
    info.start = wrapped_index(info.start + 1);
    info.capacity -= 1;
}