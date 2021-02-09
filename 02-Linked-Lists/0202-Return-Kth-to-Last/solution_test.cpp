/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-09 11:53:49 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-09 12:03:00
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Kth_to_Last, basic)
{
    struct Case {
        std::list<int> list;
        int k;
        int expect;
    };

    std::vector<Case> cases{
        {{2, 3, 4, 6, 4, 2, 3, 1}, 1, 1},
        {{2, 3, 4, 6, 4, 2, 3, 1}, 2, 3},
        {{2, 3, 4, 6, 4, 2, 3, 1}, 3, 2},
        {{2, 3, 4, 6, 4, 2, 3, 1}, 4, 4},
        {{2, 3, 4, 6, 4, 2, 3, 1}, 5, 6},
        {{2, 3, 4, 6, 4, 2, 3, 1}, 6, 4},
        {{2, 3, 4, 6, 4, 2, 3, 1}, 7, 3},
        {{2, 3, 4, 6, 4, 2, 3, 1}, 8, 2},
        {{2, 3, 4, 6, 4, 2, 3, 1}, 9, 2},
        {{2, 3, 4, 6, 4, 2, 3, 1}, 10, 2},
    };

    for (auto c : cases) {
        auto result = kth_to_last(c.list, c.k);
        EXPECT_EQ(*result, c.expect) << "Kth: " << c.k;
    }
}