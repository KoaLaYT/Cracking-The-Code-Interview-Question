#ifndef LIST_OF_DEPTHS_20210324
#define LIST_OF_DEPTHS_20210324

#include <list>
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
 * Given a binary tree, design an algorithm which creates a linked list of 
 * all the nodes at each depth.
 */
class Tree {
public:
    void set_root(Node* node) { m_root = node; }

    std::vector<std::list<Node*>> each_depths();

private:
    Node* m_root;
};

#endif