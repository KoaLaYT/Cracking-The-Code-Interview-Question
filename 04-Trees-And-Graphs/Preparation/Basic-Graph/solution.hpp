#ifndef BASIC_GRAPH_20200316
#define BASIC_GRAPH_20200316

#include <string>
#include <vector>

struct Vertice {
    char name;
    int index;
};

class Graph {
public:
    explicit Graph(std::string file);

private:
    std::vector<std::vector<Vertice*>> m_adj;
};

#endif