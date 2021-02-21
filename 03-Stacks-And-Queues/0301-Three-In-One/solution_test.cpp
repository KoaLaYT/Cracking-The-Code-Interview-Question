#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Three_in_One, basic)
{
    MultiStack stack{3};

    stack.push(0, 1);
    stack.push(0, 2);
    stack.push(0, 3);
    stack.push(1, 5);
    stack.push(2, 6);
    stack.push(0, 4);

    EXPECT_EQ(stack.peek(0), 4);
    EXPECT_EQ(stack.peek(1), 5);
    EXPECT_EQ(stack.peek(2), 6);

    int top = stack.pop(0);
    EXPECT_EQ(top, 4);
    EXPECT_EQ(stack.peek(0), 3);
}