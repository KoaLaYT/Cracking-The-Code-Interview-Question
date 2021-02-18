#include "solution.hpp"

#include <gtest/gtest.h>

#include <random>
#include <vector>

namespace helper {
static int random()
{
    static std::random_device rd;
    static std::mt19937 gen{rd()};
    static std::uniform_int_distribution<> distrib(1, 100);
    return distrib(gen);
}

static Node* random_node()
{
    return new Node{helper::random(), helper::random()};
}
}  // namespace helper

TEST(Intersection, has_intersection)
{
    std::list<Node*> list1;
    std::list<Node*> list2;

    for (int i = 0; i < 4; ++i) {
        list1.push_back(helper::random_node());
    }

    for (int i = 0; i < 2; ++i) {
        list2.push_back(helper::random_node());
    }

    // intersect begin
    Node* intersect = helper::random_node();
    list1.push_back(intersect);
    list2.push_back(intersect);
    // intersect tails
    for (int i = 0; i < 2; ++i) {
        Node* node = helper::random_node();
        list1.push_back(node);
        list2.push_back(node);
    }

    Node* result = intersection(list1, list2);
    EXPECT_TRUE(result);
    EXPECT_EQ(result, intersect);
}

TEST(Intersection, no_intersection)
{
    std::list<Node*> list1;
    std::list<Node*> list2;

    for (int i = 0; i < 7; ++i) {
        list1.push_back(helper::random_node());
    }

    for (int i = 0; i < 5; ++i) {
        list2.push_back(helper::random_node());
    }

    Node* result = intersection(list1, list2);
    EXPECT_FALSE(result);
}