#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Animal_Shelter, basic)
{
    AnimalQueue q;

    q.enqueue(std::make_unique<Cat>());
    q.enqueue(std::make_unique<Dog>());
    q.enqueue(std::make_unique<Cat>());
    q.enqueue(std::make_unique<Dog>());

    auto a1 = q.dequeue_any();
    EXPECT_EQ(a1->get_id(), 1);

    auto a2 = q.dequeue_cat();
    EXPECT_EQ(a2->get_id(), 3);

    auto null = q.dequeue_cat();
    EXPECT_EQ(null, nullptr);

    auto a3 = q.dequeue_any();
    EXPECT_EQ(a3->get_id(), 2);

    auto a4 = q.dequeue_dog();
    EXPECT_EQ(a4->get_id(), 4);
}