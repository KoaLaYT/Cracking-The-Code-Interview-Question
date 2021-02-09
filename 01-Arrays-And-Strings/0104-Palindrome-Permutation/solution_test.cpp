/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-01 22:36:06 
 * @Last Modified by:   KoaLaYT 
 * @Last Modified time: 2021-02-01 22:36:06 
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(palindrome_permutation, basic)
{
    struct Case {
        std::string input;
        bool expect;
    };

    std::vector<Case> cases{
        {"Tact Coa", true},
        {"", true},
        {"abcc", false},
        {"abcabc", true},
        {"abcdcba", true},
        {"ABCabc", true},
    };

    for (const auto& c : cases) {
        bool result = is_palindrome_permutation(c.input);
        EXPECT_EQ(result, c.expect) << "Input: " << c.input;
    }
}