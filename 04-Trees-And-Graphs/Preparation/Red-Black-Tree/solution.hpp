#ifndef RED_BLACK_TREE_20200313
#define RED_BLACK_TREE_20200313

struct Node {
    enum class Color {
        Black,
        Red
    };

    int key;
    Color color;
    Node* p;
    Node* left;
    Node* right;

    explicit Node(int k)
        : key{k},
          color{Color::Red},
          p{nil},
          left{nil},
          right{nil}
    {}

    bool is_nil() { return this == nil; }
    bool is_red() { return color == Color::Red; }
    bool is_black() { return color == Color::Black; }
    bool is_leaf() { return left->is_nil() && right->is_nil(); }

    static Node* nil;
};

class Tree {
public:
    ~Tree() { free(m_root); }

    void set_root(Node* root) { m_root = root; }
    Node* get_root() { return m_root; }

    int height() { return height(m_root); }
    Node* search(int key);
    void insert(int key);

private:
    Node* m_root{Node::nil};

    int height(Node* node);
    void free(Node* node);
};

#endif