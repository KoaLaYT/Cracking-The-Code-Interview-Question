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

    struct BFSInfo {
        enum class Color {
            White,
            Gray,
            Black
        };
        Vertex* p;  // vertex parent
        Color c;    // vertex color
        int d;      // distance from source

        bool is_white() { return c == Color::White; }
        void set_gray() { c = Color::Gray; }
        void set_black() { c = Color::Black; }
    };

    std::map<Vertex*, BFSInfo> bfs(char name);

private:
    std::map<Vertex*, std::vector<Vertex*>> m_adj;

    Vertex* findByName(char name);
};

#endif