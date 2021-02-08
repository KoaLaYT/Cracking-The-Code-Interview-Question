#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

class ListTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        list.insert(1);
        list.insert(2);
        list.insert(3);
    }

    DoublyLinkedList list;
};

TEST_F(ListTest, basic)
{
    EXPECT_EQ(list.head()->key, 3);
    EXPECT_EQ(list.head()->next->key, 2);
    EXPECT_EQ(list.head()->next->next->key, 1);
    EXPECT_EQ(list.head()->next->next->next, list.nil());

    EXPECT_EQ(list.tail()->key, 1);
    EXPECT_EQ(list.tail()->prev->key, 2);
    EXPECT_EQ(list.tail()->prev->prev->key, 3);
    EXPECT_EQ(list.tail()->prev->prev->prev, list.nil());

    EXPECT_EQ(list.search(0), list.nil());
    EXPECT_EQ(list.search(1)->key, 1);
    EXPECT_EQ(list.search(2)->key, 2);
    EXPECT_EQ(list.search(3)->key, 3);
    EXPECT_EQ(list.search(4), list.nil());
}

TEST_F(ListTest, remove_head)
{
    Node* it = list.remove(3);
    EXPECT_EQ(it->key, 3);
    EXPECT_EQ(it->prev, nullptr);
    EXPECT_EQ(it->next, nullptr);
    delete it;

    EXPECT_EQ(list.head()->key, 2);
    EXPECT_EQ(list.head()->next->key, 1);
    EXPECT_EQ(list.head()->next->next, list.nil());

    EXPECT_EQ(list.tail()->key, 1);
    EXPECT_EQ(list.tail()->prev->key, 2);
    EXPECT_EQ(list.tail()->prev->prev, list.nil());
}

TEST_F(ListTest, remove_tail)
{
    Node* it = list.remove(1);
    EXPECT_EQ(it->key, 1);
    EXPECT_EQ(it->prev, nullptr);
    EXPECT_EQ(it->next, nullptr);
    delete it;

    EXPECT_EQ(list.head()->key, 3);
    EXPECT_EQ(list.head()->next->key, 2);
    EXPECT_EQ(list.head()->next->next, list.nil());

    EXPECT_EQ(list.tail()->key, 2);
    EXPECT_EQ(list.tail()->prev->key, 3);
    EXPECT_EQ(list.tail()->prev->prev, list.nil());
}

TEST_F(ListTest, remove_middle)
{
    Node* it = list.remove(2);
    EXPECT_EQ(it->key, 2);
    EXPECT_EQ(it->prev, nullptr);
    EXPECT_EQ(it->next, nullptr);
    delete it;

    EXPECT_EQ(list.head()->key, 3);
    EXPECT_EQ(list.head()->next->key, 1);
    EXPECT_EQ(list.head()->next->next, list.nil());

    EXPECT_EQ(list.tail()->key, 1);
    EXPECT_EQ(list.tail()->prev->key, 3);
    EXPECT_EQ(list.tail()->prev->prev, list.nil());
}