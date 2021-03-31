#include "solution.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

class BSTSequencesTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        /*
                 3
             /       \
            1        5
             \      /
              2    4
         */
        Node* n1 = new Node{1};
        Node* n2 = new Node{2};
        Node* n3 = new Node{3};
        Node* n4 = new Node{4};
        Node* n5 = new Node{5};

        n1->right = n2;
        n5->left = n4;
        n3->left = n1;
        n3->right = n5;

        tree.set_root(n3);
    }

    Tree tree;
};

TEST_F(BSTSequencesTest, basic)
{
    auto result = tree.all_sequences();
    std::vector<std::list<int>> expect{
        {3, 1, 2, 5, 4},
        {3, 1, 5, 2, 4},
        {3, 1, 5, 4, 2},
        {3, 5, 4, 1, 2},
        {3, 5, 1, 2, 4},
        {3, 5, 1, 4, 2},
    };
    ASSERT_EQ(result.size(), expect.size());

    std::for_each(result.begin(), result.end(), [&](std::list<int>& list) {
        ASSERT_EQ(list.size(), expect[0].size());
        bool exist = std::any_of(expect.begin(), expect.end(), [&](std::list<int>& exp) {
            return std::equal(list.begin(), list.end(), exp.begin());
        });
        EXPECT_TRUE(exist);
    });
}