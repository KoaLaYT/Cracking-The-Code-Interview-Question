/*
 * @Author: KoaLaYT 
 * @Date: 2021-01-31 13:56:39 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-01-31 14:25:15
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Is_Unique, basic)
{
    struct Case {
        std::string input;
        bool expect;
    };

    std::vector<Case> cases{
        // {"abcde", true},
        {"abcc", false},
        {"", true},
        {".,3uy5028rhfceuncxui2hr2f82obe", false},
    };

    for (const auto& c : cases) {
        bool result = is_unique(c.input);
        EXPECT_EQ(result, c.expect)
            << "input: " << c.input
            << ", expect: " << c.expect;
    }
}