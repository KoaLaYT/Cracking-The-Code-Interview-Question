#include "solution.hpp"

#include <fstream>

Graph::Graph(std::string file)
{
    std::ifstream ifs{file};
    if (!ifs.is_open()) {
        throw std::runtime_error{"Can't open file"};
    }

    auto getOrPut = [&](char name) {
        if (m_vs.find(name) == m_vs.end()) {
            Vertex* v = new Vertex{name};
            m_vs[name] = v;
            std::vector<Vertex*> subs;
            m_adj[v] = subs;
        }
        return m_vs[name];
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

namespace impl {

struct DFSInfo {
    enum class State {
        Unvisited,
        Visiting,
        Visited
    };

    State state{State::Unvisited};

    bool has_visited() { return state != State::Unvisited; }
    void visiting() { state = State::Visiting; }
    void visited() { state = State::Visited; }
};

};  // namespace impl

static bool visit(
    Vertex* v, Vertex* t,
    std::map<Vertex*, std::vector<Vertex*>>& adj,
    std::map<Vertex*, impl::DFSInfo>& records)
{
    if (v == t) return true;

    records[v].visiting();
    for (auto& s : adj[v]) {
        if (!records[s].has_visited()) {
            bool found = visit(s, t, adj, records);
            if (found) return true;
        }
    }
    records[v].visited();
    return false;
}

bool Graph::has_route(char from, char to)
{
    if (from == to) return true;

    Vertex* f = findByName(from);
    Vertex* t = findByName(to);

    std::map<Vertex*, impl::DFSInfo> records;
    for (auto& pair : m_vs) {
        records[pair.second] = impl::DFSInfo{};
    }

    return visit(f, t, m_adj, records);
}