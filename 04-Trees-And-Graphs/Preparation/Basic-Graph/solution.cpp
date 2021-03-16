#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <queue>

Graph::Graph(std::string file)
{
    std::ifstream ifs{file};
    if (!ifs.is_open()) {
        throw std::runtime_error{"Can't open file"};
    }

    std::map<char, Vertex*> cache;
    auto getOrPut = [&](char name) {
        if (cache.find(name) == cache.end()) {
            Vertex* v = new Vertex{name};
            cache[name] = v;
            std::vector<Vertex*> subs;
            m_adj[v] = subs;
        }
        return cache[name];
    };

    char name, delim;
    while (ifs >> name >> delim) {
        Vertex* v = getOrPut(name);

        char sub;
        while (ifs >> sub) {
            if (sub == ';') break;
            if (sub == ',') continue;
            Vertex* s = getOrPut(sub);
            m_adj[v].push_back(s);
        }
    }
}

Vertex* Graph::findByName(char name)
{
    for (auto& it : m_adj) {
        if (it.first->name == name) {
            return it.first;
        }
    }
    return nullptr;
}

std::map<Vertex*, Graph::BFSInfo> Graph::bfs(char name)
{
    Vertex* v = findByName(name);
    if (!v) throw std::runtime_error{"No such vertex"};
    // Init result
    std::map<Vertex*, Graph::BFSInfo> result;
    for (auto& pair : m_adj) {
        result[pair.first] = Graph::BFSInfo{nullptr, Graph::BFSInfo::Color::White, -1};
    }

    result[v].set_gray();
    result[v].d = 0;

    std::queue<Vertex*> q;
    q.push(v);
    while (!q.empty()) {
        Vertex* front = q.front();
        q.pop();
        auto& info = result[front];

        for (Vertex* s : m_adj[front]) {
            if (result[s].is_white()) {
                result[s].p = front;
                result[s].set_gray();
                result[s].d = info.d + 1;
                q.push(s);
            }
        }

        info.set_black();
    }

    return result;
}