#include "solution.hpp"

#include <gtest/gtest.h>

#define BASE "/Users/koalayt/Study/Algorithm/Cracking-The-Code-Interview/04-Trees-And-Graphs/Preparation/Basic-Graph/"
#define PATH(p) BASE p

TEST(Basic_Graph, graph_construct)
{
    Graph g{PATH("graph.txt")};
}