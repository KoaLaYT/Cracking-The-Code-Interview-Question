#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

class FirstCommonAncestorTest : public ::testing::Test {
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

    Tree tree;
};

struct Case {
    int a;
    int b;
    int expect;
};

TEST_F(FirstCommonAncestorTest, find)
{
    {
        Node* a = tree.find(6);
        ASSERT_TRUE(a);
        EXPECT_EQ(a->key, 6);
    }

    {
        Node* a = tree.find(9);
        ASSERT_TRUE(a);
        EXPECT_EQ(a->key, 9);
    }

    {
        Node* a = tree.find(1);
        ASSERT_FALSE(a);
    }
}

TEST_F(FirstCommonAncestorTest, basic)
{
    std::vector<Case> cases{
        {4, 13, 6},
        {2, 4, 3},
        {2, 17, 15},
        {1, 20, -1},
    };

    for (auto& c : cases) {
        Node* a = tree.find(c.a);
        Node* b = tree.find(c.b);
        Node* result = tree.first_common_ancestor(a, b);
        if (c.expect > 0) {
            ASSERT_TRUE(result);
            EXPECT_EQ(result->key, c.expect);
        } else {
            ASSERT_FALSE(result);
        }
    }
}