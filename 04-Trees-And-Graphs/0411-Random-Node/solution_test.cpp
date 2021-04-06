#include "solution.hpp"

#include <gtest/gtest.h>

#include <cstdio>
#include <map>
#include <vector>

class RandomNodeTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        std::vector<int> nodes{15, 6, 18, 3, 7, 17, 20, 2, 4, 13};
        for (int key : nodes) {
            tree.insert(key);
        }
    }

    Tree tree;
};

TEST_F(RandomNodeTest, basic)
{
    int loop = 1000000;
    std::map<Node*, int> counts;

    while (loop-- > 0) {
        Node* n = tree.random_node();
        ASSERT_TRUE(n);

        if (counts.find(n) == counts.end()) {
            counts[n] = 0;
        }
        counts[n] += 1;
    }

    ASSERT_EQ(counts.size(), tree.size());
    for (auto& pair : counts) {
        std::printf("Node(%02d): %06d\n", pair.first->key, pair.second);
    }
}