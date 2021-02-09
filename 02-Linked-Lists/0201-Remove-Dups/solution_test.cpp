/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-09 10:47:51 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-09 11:17:28
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Remove_Dups, basic)
{
    struct Case {
        std::list<int> input;
        std::list<int> expect;
    };

    std::vector<Case> cases{
        {{2, 3, 4, 1, 2, 3, 4, 5}, {2, 3, 4, 1, 5}},
        {{1}, {1}},
        {{}, {}},
        {{1, 1, 2, 3, 4, 3, 2, 1}, {1, 2, 3, 4}},
    };

    for (auto& c : cases) {
        remove_dups(c.input);
        EXPECT_EQ(c.input, c.expect);
    }
}