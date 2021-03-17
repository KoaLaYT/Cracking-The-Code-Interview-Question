#ifndef BASIC_GRAPH_20200316
#define BASIC_GRAPH_20200316

#include <map>
#include <string>
#include <vector>

struct Vertex {
    char name;
};

class Graph {
public:
    explicit Graph(std::string file);

    enum class Color {
        White,
        Gray,
        Black
    };

    struct BFSInfo {
        Vertex* p;  // vertex parent
        Color c;    // vertex color
        int d;      // distance from source

        bool is_white() { return c == Color::White; }
        void set_gray() { c = Color::Gray; }
        void set_black() { c = Color::Black; }
    };

    struct DFSInfo {
        Vertex* p;  // vertex parent
        Color c;    // vertex color
        int d;      // discover timestamp
        int f;      // finish timestamp

        bool is_white() { return c == Color::White; }
        void set_gray() { c = Color::Gray; }
        void set_black() { c = Color::Black; }
    };

    std::map<Vertex*, BFSInfo> bfs(char name);
    std::map<Vertex*, DFSInfo> dfs();

private:
    std::map<Vertex*, std::vector<Vertex*>> m_adj;

    Vertex* findByName(char name);
    int dfs_visit(std::map<Vertex*, DFSInfo>& result, Vertex* v, int time);
};

#endif