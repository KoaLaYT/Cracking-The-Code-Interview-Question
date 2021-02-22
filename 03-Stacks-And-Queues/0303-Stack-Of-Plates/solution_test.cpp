#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Stack_of_Plates, basic)
{
    SetOfStacks s{3};

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    EXPECT_EQ(s.num(), 2);
    EXPECT_EQ(s.pop_at(0), 3);

    EXPECT_EQ(s.pop(), 4);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
}

TEST(Stack_of_Plates, pop_previous)
{
    SetOfStacks s{3};

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    EXPECT_EQ(s.pop_at(0), 3);
    EXPECT_EQ(s.pop_at(0), 2);
    EXPECT_EQ(s.pop_at(0), 1);
    EXPECT_EQ(s.num(), 1);
    EXPECT_EQ(s.pop(), 4);

    EXPECT_TRUE(s.empty());
}