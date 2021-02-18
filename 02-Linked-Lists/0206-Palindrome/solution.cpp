#include "solution.hpp"

#include <stack>

namespace impl {
// [1] Reverse the given list, and compare each node
static bool reverse(const std::list<int>& list);

// [2] Using a stack to store first half values
static bool stack(const std::list<int>& list);

// [3] Recursivly comparing nodes
using It = std::list<int>::const_iterator;

struct Result {
    It it;
    bool is_equal;
};

static Result recurse(It it, int len);
};  // namespace impl

bool is_palindrome(const std::list<int>& list)
{
    // [1]
    // return impl::reverse(list);

    // [2]
    // return impl::stack(list);

    // [3]
    int len = list.size();
    return impl::recurse(list.cbegin(), len).is_equal;
}

// =====================
// IMPLEMENTATION DETAIL
// =====================
namespace impl {

bool reverse(const std::list<int>& list)
{
    std::list<int> copy{list};
    copy.reverse();

    for (auto it1 = list.cbegin(), it2 = copy.cbegin(); it1 != list.cend(); ++it1, ++it2) {
        if (*it1 != *it2) return false;
    }

    return true;
}

bool stack(const std::list<int>& list)
{
    std::stack<int> half;

    int len = 0;
    auto slow = list.cbegin();
    for (auto fast = list.cbegin(); fast != list.cend(); /* */) {
        half.push(*slow++);
        ++fast;
        ++len;
        if (fast != list.cend()) {
            ++fast;
            ++len;
        }
    }

    if (len % 2 == 1) half.pop();

    while (slow != list.cend()) {
        auto top = half.top();
        half.pop();
        if (*slow++ != top) {
            return false;
        }
    }

    return true;
}

Result recurse(It it, int len)
{
    if (len == 0) return Result{it, true};
    if (len == 1) return Result{++it, true};

    It next = it;
    Result result = recurse(++next, len - 2);
    if (!result.is_equal) return Result{it, false};

    bool is_equal = *result.it == *it;
    return Result{++result.it, is_equal};
}

};  // namespace impl