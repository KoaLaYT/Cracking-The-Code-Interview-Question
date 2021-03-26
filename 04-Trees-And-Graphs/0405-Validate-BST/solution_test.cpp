#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

class ValidateBSTTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        Node* n5 = new Node{5};
        Node* n11 = new Node{11};
        Node* n6 = new Node{6};
        n6->left = n5;
        n6->right = n11;

        Node* n4 = new Node{4};
        Node* n9 = new Node{9};
        n9->left = n4;

        Node* n2 = new Node{2};

        Node* n7 = new Node{7};
        n7->left = n2;
        n7->right = n6;

        Node* n52 = new Node{5};
        n52->right = n9;

        Node* n22 = new Node{2};
        n22->left = n7;
        n22->right = n52;

        tree.set_root(n22);
    }

    Tree tree;
};

TEST_F(ValidateBSTTest, basic)
{
    bool result = tree.validate_bst();
    EXPECT_EQ(result, false);
}