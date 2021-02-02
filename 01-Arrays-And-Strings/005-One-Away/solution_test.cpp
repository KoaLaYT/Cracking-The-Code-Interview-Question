/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-02 22:57:20 
 * @Last Modified by:   KoaLaYT 
 * @Last Modified time: 2021-02-02 22:57:20 
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(One_Away, basic)
{
    struct Case {
        std::string s1;
        std::string s2;
        bool expect;
    };

    std::vector<Case> cases{
        {"apple", "apple", true},
        {"", "", true},
        {"apple", "bpple", true},
        {"apple", "appe", true},
        {"appe", "apple", true},
        {"appl", "apple", true},
        {"pple", "apple", true},
        {"gfweiu", "bewri", false},
        {"qd", "whfui", false},
        {"apple", "appc", false},
    };

    for (const auto& c : cases) {
        bool result = is_one_away(c.s1, c.s2);
        EXPECT_EQ(result, c.expect) << "String 1: " << c.s1 << '\n'
                                    << "String 2: " << c.s2;
    }
}