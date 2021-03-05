#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Queue_Via_Stack, basic)
{
    MyQueue q;

    EXPECT_EQ(q.size(), 0);

    q.add(1);
    q.add(2);
    q.add(3);

    EXPECT_EQ(q.peek(), 1);
    EXPECT_EQ(q.remove(), 1);
    EXPECT_EQ(q.peek(), 2);
    EXPECT_EQ(q.remove(), 2);

    EXPECT_EQ(q.size(), 1);

    q.add(4);
    q.add(5);

    EXPECT_EQ(q.size(), 3);

    EXPECT_EQ(q.peek(), 3);
    EXPECT_EQ(q.remove(), 3);
    EXPECT_EQ(q.remove(), 4);
    EXPECT_EQ(q.remove(), 5);

    EXPECT_EQ(q.size(), 0);
}