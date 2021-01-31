#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Check_Permutation, basic)
{
    struct Case {
        std::string first;
        std::string second;
        bool expect;
    };

    std::vector<Case> cases{
        {"dog", "god", true},
        {"", "", true},
        {"dog", "God", false},
        {"herfuir", "1da", false},
        {"aabbcc", "bbcca", false},
        {"aabbcc", "babcca", true},
    };

    for (const auto& c : cases) {
        bool result = check_permutation(c.first, c.second);

        EXPECT_EQ(result, c.expect)
            << "First: " << c.first << ", Second: " << c.second << '\n'
            << "Expect: " << c.expect;
    }
}