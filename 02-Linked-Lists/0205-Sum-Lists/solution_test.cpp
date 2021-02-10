/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-10 16:04:33 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-10 16:47:42
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

struct Case {
    std::list<int> num1;
    std::list<int> num2;
    std::list<int> expect;
};

TEST(Sum_Lists, reverse_order)
{
    std::vector<Case> cases_reverse{
        {{7, 1, 6}, {5, 9, 2}, {2, 1, 9}},
        {{7, 1, 6}, {5, 2}, {2, 4, 6}},
        {{7, 6}, {5, 9, 2}, {2, 6, 3}},
        {{7, 1, 9}, {5, 9, 2}, {2, 1, 2, 1}},
        {{1, 2, 3}, {}, {1, 2, 3}},
    };

    for (const auto& c : cases_reverse) {
        auto result = sum_reverse_order(c.num1, c.num2);
        EXPECT_EQ(result, c.expect);
    }
}

TEST(Sum_Lists, forward_order)
{
    std::vector<Case> cases_forward{
        {{6, 1, 7}, {2, 9, 5}, {9, 1, 2}},
        {{6, 7}, {2, 9, 5}, {3, 6, 2}},
        {{6, 1, 7}, {2, 5}, {6, 4, 2}},
        {{9, 1, 7}, {2, 9, 5}, {1, 2, 1, 2}},
    };

    for (const auto& c : cases_forward) {
        auto result = sum_forward_order(c.num1, c.num2);
        EXPECT_EQ(result, c.expect);
    }
}