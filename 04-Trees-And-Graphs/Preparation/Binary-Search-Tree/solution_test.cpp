#include "solution.hpp"

#include <gtest/gtest.h>

class TreeTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        Node* n9 = new Node{9};
        Node* n13 = new Node{13};
        n9->p = n13;
        n13->left = n9;

        Node* n2 = new Node{2};
        Node* n4 = new Node{4};
        Node* n3 = new Node{3};
        n2->p = n3;
        n4->p = n3;
        n3->left = n2;
        n3->right = n4;

        Node* n7 = new Node{7};
        n13->p = n7;
        n7->right = n13;

        Node* n6 = new Node{6};
        n3->p = n6;
        n7->p = n6;
        n6->left = n3;
        n6->right = n7;

        Node* n17 = new Node{17};
        Node* n20 = new Node{20};
        Node* n18 = new Node{18};
        n17->p = n18;
        n20->p = n18;
        n18->left = n17;
        n18->right = n20;

        Node* root = new Node{15};
        n6->p = root;
        n18->p = root;
        root->left = n6;
        root->right = n18;

        tree.set_root(root);
    }

    void tranverse(int* order)
    {
        Node* node = tree.minimum();
        int index = 0;
        while (node) {
            EXPECT_EQ(node->key, order[index++]);
            node = tree.successor(node);
        }
    }

    Tree tree;
};

TEST_F(TreeTest, height)
{
    EXPECT_EQ(tree.height(), 5);
}

TEST_F(TreeTest, search)
{
    Node* found = tree.search(15);
    ASSERT_TRUE(found);
    ASSERT_TRUE(found->left);
    ASSERT_TRUE(found->right);
    EXPECT_EQ(found->left->key, 6);
    EXPECT_EQ(found->right->key, 18);

    Node* not_found = tree.search(21);
    EXPECT_TRUE(!not_found);
}

TEST_F(TreeTest, minmax)
{
    Node* min = tree.minimum();
    ASSERT_TRUE(min);
    EXPECT_EQ(min->key, 2);

    Node* max = tree.maximum();
    ASSERT_TRUE(max);
    EXPECT_EQ(max->key, 20);
}

TEST_F(TreeTest, successor_has_right_children)
{
    Node* node = tree.search(7);
    ASSERT_TRUE(node);
    Node* successor = tree.successor(node);
    ASSERT_TRUE(successor);
    EXPECT_EQ(successor->key, 9);
}

TEST_F(TreeTest, successor_without_right_children)
{
    Node* node = tree.search(4);
    ASSERT_TRUE(node);
    Node* successor = tree.successor(node);
    ASSERT_TRUE(successor);
    EXPECT_EQ(successor->key, 6);
}

TEST_F(TreeTest, successor_maximum)
{
    Node* max = tree.maximum();
    Node* successor = tree.successor(max);
    EXPECT_TRUE(!successor);
}

TEST_F(TreeTest, successor_comprehensive)
{
    int order[] = {2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};
    tranverse(order);
}

TEST_F(TreeTest, predecessor_has_left_children)
{
    Node* node = tree.search(6);
    ASSERT_TRUE(node);
    Node* predecessor = tree.predecessor(node);
    ASSERT_TRUE(predecessor);
    EXPECT_EQ(predecessor->key, 4);
}

TEST_F(TreeTest, predecessor_without_left_children)
{
    Node* node = tree.search(17);
    ASSERT_TRUE(node);
    Node* predecessor = tree.predecessor(node);
    ASSERT_TRUE(predecessor);
    EXPECT_EQ(predecessor->key, 15);
}

TEST_F(TreeTest, predecessor_minimum)
{
    Node* min = tree.minimum();
    Node* predecessor = tree.predecessor(min);
    EXPECT_TRUE(!predecessor);
}

TEST_F(TreeTest, predecessor_comprehensive)
{
    int order[] = {20, 18, 17, 15, 13, 9, 7, 6, 4, 3, 2};
    Node* node = tree.maximum();
    int index = 0;
    while (node) {
        EXPECT_EQ(node->key, order[index++]);
        node = tree.predecessor(node);
    }
}

TEST_F(TreeTest, insert)
{
    tree.insert(5);
    Node* node = tree.search(4);
    ASSERT_TRUE(node);
    ASSERT_TRUE(node->right);
    EXPECT_EQ(node->right->key, 5);
}

TEST_F(TreeTest, remove_no_children)
{
    tree.remove(4);
    int order[] = {2, 3, 6, 7, 9, 13, 15, 17, 18, 20};
    tranverse(order);
}

TEST_F(TreeTest, remove_swap_right_children)
{
    tree.remove(3);
    int order[] = {2, 4, 6, 7, 9, 13, 15, 17, 18, 20};
    tranverse(order);
}

TEST_F(TreeTest, remove_swap_deep_children)
{
    tree.remove(7);
    int order[] = {2, 3, 4, 6, 9, 13, 15, 17, 18, 20};
    tranverse(order);
}