/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-03 22:38:12 
 * @Last Modified by:   KoaLaYT 
 * @Last Modified time: 2021-02-03 22:38:12 
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(String_Compression, basic)
{
    struct Case {
        std::string input;
        std::string expect;
    };

    std::vector<Case> cases{
        {"abc", "abc"},
        {"aabbbcc", "a2b3c2"},
        {"aabbcc", "aabbcc"},
    };

    for (const auto& c : cases) {
        std::string result = string_compression(c.input);
        EXPECT_EQ(result, c.expect) << "Input: " << c.input;
    }
}