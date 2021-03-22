#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

#define BASE "/Users/koalayt/Study/Algorithm/Cracking-The-Code-Interview/04-Trees-And-Graphs/0401-Route-Between-Nodes/"
#define PATH(p) BASE p

TEST(Route_Between_Nodes, basic)
{
    Graph g{PATH("graph.txt")};

    struct Case {
        char from;
        char to;
        bool expect;
    };

    std::vector<Case> cases{
        {'s', 'q', false},
        {'q', 'v', true},
        {'r', 'w', true},
        {'r', 'r', true},
        {'r', 'x', true},
    };

    for (auto& c : cases) {
        bool result = g.has_route(c.from, c.to);
        EXPECT_EQ(result, c.expect)
            << c.from << " -> " << c.to;
    }
}