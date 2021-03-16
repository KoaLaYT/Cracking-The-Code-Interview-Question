#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <map>

Graph::Graph(std::string file)
{
    std::ifstream ifs{file};
    if (!ifs.is_open()) {
        throw std::runtime_error{"Can't open file"};
    }

    std::map<char, Vertice*> cache;
    int index = 0;
    auto getOrPut = [&](char name) {
        if (cache.find(name) == cache.end()) {
            cache[name] = new Vertice{name, index++};
            std::vector<Vertice*> subs;
            m_adj.push_back(subs);
        }
        return cache[name];
    };

    char name, delim;
    while (ifs >> name >> delim) {
        Vertice* v = getOrPut(name);

        char sub;
        while (ifs >> sub) {
            if (sub == ';') break;
            if (sub == ',') continue;
            Vertice* s = getOrPut(sub);
            m_adj[v->index].push_back(s);
        }
    }
}