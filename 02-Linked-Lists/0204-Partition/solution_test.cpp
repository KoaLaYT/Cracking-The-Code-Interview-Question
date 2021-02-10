/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-10 10:25:14 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-10 11:12:10
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Partition, basic)
{
    struct Case {
        std::list<int> input;
        int pivot;
        std::list<int> expect;
    };

    std::vector<Case> cases{
        {{3, 5, 8, 5, 10, 2, 1}, 5, {3, 2, 1, 5, 8, 5, 10}},
        {{3, 5, 8, 5, 10, 2, 1}, 2, {1, 3, 5, 8, 5, 10, 2}},
        {{3, 5, 8, 5, 10, 2, 1}, 10, {3, 5, 8, 5, 2, 1, 10}},
        {{}, 10, {}},
    };

    for (auto c : cases) {
        partition(c.input, c.pivot);
        EXPECT_EQ(c.input, c.expect) << "Pivot: " << c.pivot;
    }
}