#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

class CheckSubtreeTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        Node* n9 = new Node{9};
        Node* n13 = new Node{13};
        n13->left = n9;

        Node* n2 = new Node{2};
        Node* n4 = new Node{4};
        Node* n3 = new Node{3};
        n3->left = n2;
        n3->right = n4;

        Node* n7 = new Node{7};
        n7->right = n13;

        Node* n6 = new Node{6};
        n6->left = n3;
        n6->right = n7;

        Node* n17 = new Node{17};
        Node* n20 = new Node{20};
        Node* n18 = new Node{18};
        n18->left = n17;
        n18->right = n20;

        Node* root = new Node{15};
        root->left = n6;
        root->right = n18;

        t1 = root;
        t2 = n7;

        t3 = new Node{21};
    }

    Node* t1;
    Node* t2;
    Node* t3;
};

TEST_F(CheckSubtreeTest, basic)
{
    EXPECT_TRUE(is_subtree(t1, t2));
    EXPECT_FALSE(is_subtree(t2, t1));
    EXPECT_FALSE(is_subtree(t1, t3));
}