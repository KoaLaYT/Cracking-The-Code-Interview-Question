#ifndef FIRST_COMMON_ANCESTOR_20210330
#define FIRST_COMMON_ANCESTOR_20210330

struct Node {
    int key;
    Node* p;
    Node* left;
    Node* right;
};

/**
 * Design an algorithm and write code to find the first common ancestor
 * of two nodes in a binary tree. Avoid storing additional nodes in a 
 * data structure.
 */
class Tree {
public:
    void set_root(Node* node) { m_root = node; }

    Node* first_common_ancestor(Node* a, Node* b);

    // for easy test
    Node* find(int key);

private:
    Node* m_root;
};

#endif