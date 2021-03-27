#ifndef SUCCESSOR_20210327
#define SUCCESSOR_20210327

struct Node {
    int key;
    Node* p;
    Node* left;
    Node* right;
};

/**
 * Write an algorithm to find the 'next' node (i.e., in-order successor) of a given node
 * in a binary search tree. You may assume that each node has a link to its parent.
 */
class Tree {
public:
    void set_root(Node* node) { m_root = node; }

    Node* successor(Node* node);

    // For easy test
    Node* search(int key);
    Node* minimum();

private:
    Node* m_root;
};

#endif