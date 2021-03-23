#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Minimal_Tree, basic)
{
    std::vector<int> input{1, 2, 3, 4, 5};
    Tree tree{input};

    ASSERT_TRUE(tree.root());
    EXPECT_EQ(tree.root()->key, 3);

    ASSERT_TRUE(tree.root()->left);
    EXPECT_EQ(tree.root()->left->key, 1);
    ASSERT_TRUE(tree.root()->right);
    EXPECT_EQ(tree.root()->right->key, 4);

    EXPECT_FALSE(tree.root()->left->left);
    ASSERT_TRUE(tree.root()->left->right);
    EXPECT_EQ(tree.root()->left->right->key, 2);

    EXPECT_FALSE(tree.root()->right->left);
    ASSERT_TRUE(tree.root()->right->right);
    EXPECT_EQ(tree.root()->right->right->key, 5);
}