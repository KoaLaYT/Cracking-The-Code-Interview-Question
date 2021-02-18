#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Palindrome, basic)
{
    struct Case {
        std::list<int> input;
        bool expect;
    };

    std::vector<Case> cases{
        {{1, 2, 3, 2, 1}, true},
        {{}, true},
        {{1}, true},
        {{1, 2, 3, 2}, false},
        {{1, 2, 2, 1}, true},
        {{1, 2, 3}, false},
    };

    for (const auto& c : cases) {
        bool result = is_palindrome(c.input);
        EXPECT_EQ(result, c.expect);
    }
}