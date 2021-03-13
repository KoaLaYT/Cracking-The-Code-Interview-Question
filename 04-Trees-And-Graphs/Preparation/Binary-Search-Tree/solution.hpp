#ifndef BINARY_SEARCH_TREE_20200312
#define BINARY_SEARCH_TREE_20200312

/**
 * For Simplicity, raw pointer is used and not using template
 */
struct Node {
    int key;
    Node* p;  // pointer to parent node
    Node* left;
    Node* right;

    explicit Node(int k)
        : key{k},
          p{nullptr},
          left{nullptr},
          right{nullptr}
    {}
};

class Tree {
public:
    ~Tree() { free(m_root); }

    void set_root(Node* root) { m_root = root; }

    int height() { return height(m_root); }
    Node* search(int key) { return search(m_root, key); }
    Node* minimum() { return minimum(m_root); }
    Node* maximum() { return maximum(m_root); }
    Node* successor(Node* node);
    Node* predecessor(Node* node);
    void insert(int key);
    void remove(int key);

private:
    Node* m_root{nullptr};

    Node* search(Node* node, int key);
    Node* minimum(Node* node);
    Node* maximum(Node* node);
    void transplant(Node* a, Node* b);
    int height(Node* node);
    void free(Node* node);
};

#endif