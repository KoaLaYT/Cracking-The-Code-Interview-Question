#ifndef ROUTE_BETWEEN_NODES_20210319
#define ROUTE_BETWEEN_NODES_20210319

#include <map>
#include <string>
#include <vector>

struct Vertex {
    char name;
};

/**
 * Given a directed graph, design an algorithm to find out 
 * whether there is a route between two nodes
 */
class Graph {
public:
    explicit Graph(std::string file);

    bool has_route(char from, char to);

private:
    std::map<Vertex*, std::vector<Vertex*>> m_adj;
    std::map<char, Vertex*> m_vs;

    Vertex* findByName(char n)
    {
        Vertex* v = m_vs[n];
        if (!v) throw std::runtime_error{"No such vertex"};
        return v;
    }
};

#endif