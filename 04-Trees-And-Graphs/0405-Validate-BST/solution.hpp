#ifndef VALIDATE_BST_20210326
#define VALIDATE_BST_20210326

struct Node {
    int key;
    Node* left;
    Node* right;
};

/**
 * Implement a function to check if a binary tree is a binary search tree.
 */
class Tree {
public:
    void set_root(Node* node) { m_root = node; }

    bool validate_bst();

private:
    Node* m_root;
};

#endif