#include "solution.hpp"

#include <gtest/gtest.h>

#define BASE "/Users/koalayt/Study/Algorithm/Cracking-The-Code-Interview/04-Trees-And-Graphs/Preparation/Basic-Graph/"
#define PATH(p) BASE p

TEST(Basic_Graph, graph_construct)
{
    Graph g{PATH("bfs-graph.txt")};
}

TEST(Basic_Graph, bfs)
{
    Graph g{PATH("bfs-graph.txt")};

    struct Case {
        char source;
        std::map<char, int> expect;
    };

    std::vector<Case> cases{
        {
            's',
            {
                {'r', 1},
                {'s', 0},
                {'v', 2},
                {'x', 2},
                {'w', 1},
                {'t', 2},
                {'u', 3},
                {'y', 3},
            },
        },
        {
            't',
            {
                {'r', 3},
                {'s', 2},
                {'v', 4},
                {'x', 1},
                {'w', 1},
                {'t', 0},
                {'u', 1},
                {'y', 2},
            },
        }};

    for (auto& c : cases) {
        auto result = g.bfs(c.source);
        ASSERT_EQ(result.size(), 8);

        for (auto& pair : result) {
            EXPECT_EQ(pair.second.c, Graph::Color::Black);
            EXPECT_EQ(pair.second.d, c.expect[pair.first->name]);
        }
    }
}

static void repeat(int times, std::function<void(void)> action)
{
    while (times-- > 0) {
        action();
    }
}

TEST(Basic_Graph, dfs)
{
    Graph g{PATH("dfs-graph.txt")};

    repeat(100, [&]() {
        auto result = g.dfs();
        ASSERT_EQ(result.size(), 6);

        for (auto& pair : result) {
            EXPECT_EQ(pair.second.c, Graph::Color::Black);
            Vertex* p = pair.second.p;
            if (p) {
                EXPECT_EQ(pair.second.d, result[p].d + 1);
                EXPECT_EQ(pair.second.f, result[p].f - 1);
            }
        }
    });
}