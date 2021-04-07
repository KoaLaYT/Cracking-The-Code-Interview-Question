#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

class PathsWithSumTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        Node* n1 = new Node{3};
        Node* n2 = new Node{-2};
        Node* n3 = new Node{1};

        Node* n4 = new Node{3};
        n4->left = n1;
        n4->right = n2;

        Node* n5 = new Node{2};
        n5->right = n3;

        Node* n6 = new Node{11};

        Node* n7 = new Node{5};
        Node* n8 = new Node{-3};

        n7->left = n4;
        n7->right = n5;

        n8->right = n6;

        root = new Node{10};
        root->left = n7;
        root->right = n8;
    }

    Node* root;
};

struct Case {
    int sum;
    int expect;
};

TEST_F(PathsWithSumTest, basic)
{
    std::vector<Case> cases{
        {8, 3},
        {6, 2},
        {7, 2},
        {1, 2},
        {3, 3},
    };

    for (auto c : cases) {
        int result = path_with_sum(root, c.sum);
        EXPECT_EQ(result, c.expect) << "sum: " << c.sum;
    }
}