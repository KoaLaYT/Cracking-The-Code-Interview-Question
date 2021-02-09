#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(String_Rotation, basic)
{
    struct Case {
        std::string s1;
        std::string s2;
        bool expect;
    };

    std::vector<Case> cases{
        {"waterbottle", "erbottlewat", true},
        {"", "", true},
        {"abc", "cabd", false},
    };

    for (const auto& c : cases) {
        bool result = is_rotation(c.s1, c.s2);
        EXPECT_EQ(result, c.expect) << "S1: " << c.s1 << '\n'
                                    << "S2: " << c.s2;
    }
}