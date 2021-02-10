/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-09 17:55:55 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-09 18:48:50
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <cstdio>
#include <vector>

TEST(Delete_Middle_Node, basic)
{
    struct Case {
        SinglyLinkedList list;
        int pos;
        SinglyLinkedList expect;
    };

    std::vector<Case> cases{
        {{1, 2, 3, 4, 5, 6, 7}, 1, {1, 3, 4, 5, 6, 7}},
        {{1, 2, 3, 4, 5, 6, 7}, 2, {1, 2, 4, 5, 6, 7}},
        {{1, 2, 3, 4, 5, 6, 7}, 3, {1, 2, 3, 5, 6, 7}},
        {{1, 2, 3, 4, 5, 6, 7}, 4, {1, 2, 3, 4, 6, 7}},
        {{1, 2, 3, 4, 5, 6, 7}, 5, {1, 2, 3, 4, 5, 7}},
    };

    for (auto& c : cases) {
        auto it = c.list.begin();

        while (c.pos-- > 0) ++it;

        delete_middle_node(it);

        auto result_it = c.list.begin();
        auto expect_it = c.expect.begin();
        while (result_it != c.list.end() && expect_it != c.expect.end()) {
            EXPECT_EQ(*result_it, *expect_it);
            ++expect_it;
            ++result_it;
        }
        EXPECT_TRUE(result_it == c.list.end());
        EXPECT_TRUE(expect_it == c.expect.end());
    }
}