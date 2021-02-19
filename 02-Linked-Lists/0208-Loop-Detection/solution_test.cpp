#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

struct Case {
    Node* root{nullptr};
    Node* expect{nullptr};

    Case(const std::vector<int>& list, int loop_begin)
    {
        Node* last = new Node{list.back()};
        root = last;

        for (int i = list.size() - 2; i >= 0; --i) {
            Node* node = new Node{list[i]};
            node->next = root;
            root = node;
            if (list[i] == loop_begin) {
                last->next = node;
                expect = node;
            }
        }
    }
};

TEST(Loop_Detection, basic)
{
    std::vector<Case> cases{
        {{1, 2, 3, 4, 5, 6, 7}, 3},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 7},
    };

    for (auto c : cases) {
        Node* result = loop_detect(c.root);
        EXPECT_EQ(result, c.expect);
    }
}