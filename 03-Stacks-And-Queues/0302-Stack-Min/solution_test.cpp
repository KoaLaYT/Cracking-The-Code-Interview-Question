#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Stack_Min, basic)
{
    StackWithMin s;

    s.push(2);
    s.push(3);
    s.push(1);
    s.push(4);
    EXPECT_EQ(s.min(), 1);

    s.pop();
    s.pop();
    EXPECT_EQ(s.min(), 2);

    s.push(2);
    s.push(2);
    s.push(1);
    EXPECT_EQ(s.min(), 1);

    s.pop();
    s.pop();
    s.pop();
    EXPECT_EQ(s.min(), 2);
}