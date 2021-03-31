#include "solution.hpp"

namespace impl {

static void weave_lists(std::list<int>& left,
                        std::list<int>& right,
                        std::list<int>& prefix,
                        std::vector<std::list<int>>& result)
{
    if (left.empty() || right.empty()) {
        std::list<int> clone{prefix};
        auto push_all = [&](std::list<int>& list) {
            for (auto it = list.begin(); it != list.end(); ++it) {
                clone.push_back(*it);
            }
        };
        push_all(left);
        push_all(right);
        result.push_back(clone);
        return;
    }

    auto get_first = [&](std::list<int>& list) {
        int front = list.front();
        list.pop_front();
        prefix.push_back(front);
    };

    auto restore = [&](std::list<int>& list) {
        int last = prefix.back();
        prefix.pop_back();
        list.push_front(last);
    };

    auto try_list = [&](std::list<int>& list) {
        get_first(list);
        weave_lists(left, right, prefix, result);
        restore(list);
    };

    try_list(left);
    try_list(right);
}

static std::vector<std::list<int>> all_sequences(Node* node)
{
    std::vector<std::list<int>> result{};

    if (!node) {
        std::list<int> empty{};
        result.push_back(empty);
        return result;
    }
    auto left_seq = all_sequences(node->left);
    auto right_seq = all_sequences(node->right);

    std::list<int> prefix{node->key};
    for (auto& left : left_seq) {
        for (auto& right : right_seq) {
            weave_lists(left, right, prefix, result);
        }
    }

    return result;
}

};  // namespace impl

std::vector<std::list<int>> Tree::all_sequences()
{
    return impl::all_sequences(m_root);
}