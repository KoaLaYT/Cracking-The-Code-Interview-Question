#ifndef THREE_IN_ONE_20210219
#define THREE_IN_ONE_20210219

#include <vector>

/**
 * Describe how you could use a single array to implement three stack.
 */
class MultiStack {
public:
    void push(int stack_num, int value);
    int pop(int stack_num);
    int peek(int stack_num);
    bool is_empty(int stack_num);
    bool is_full(int stack_num);
    bool is_all_full();

    explicit MultiStack(int init_size);

private:
    static constexpr int STACK_NUM = 3;

    struct StackInfo {
        int start;
        int capacity;
        int size;

        bool is_full() { return size == capacity; }
        bool is_empty() { return size == 0; }
    };

    std::vector<StackInfo> m_stack_infos;
    std::vector<int> m_values;

    int next_idx(int stack_num);

    void expand(int stack_num);
    void shift(int stack_num);

    int wrapped_index(int index) { return index % m_values.size(); }
};

#endif