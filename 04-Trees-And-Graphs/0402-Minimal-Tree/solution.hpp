#ifndef MINIMAL_TREE_20210323
#define MINIMAL_TREE_20210323

#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;

    explicit Node(int k)
        : key{k},
          left{nullptr},
          right{nullptr} {}
};

/**
 * Given a sorted (increasing order) array with unique integer elements,
 * write an algorithm to create a binary search tree with minimal height.
 */
class Tree {
public:
    explicit Tree(std::vector<int>& sorted);

    ~Tree() { free(m_root); }

    const Node* root() { return m_root; }

private:
    Node* m_root{nullptr};

    void free(Node* node);
};

#endif