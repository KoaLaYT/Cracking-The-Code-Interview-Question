#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Sort_Stack, basic)
{
    struct Case {
        std::vector<int> input;
        std::vector<int> expect;
    };

    std::vector<Case> cases{
        {
            {3, 2, 1, 5, 4, 6},
            {1, 2, 3, 4, 5, 6},
        },
    };

    for (auto& c : cases) {
        std::stack<int> input;
        for (int i : c.input) {
            input.push(i);
        }
        sort_stack(input);
        for (int i : c.expect) {
            EXPECT_EQ(input.top(), i);
            input.pop();
        }
    }
}