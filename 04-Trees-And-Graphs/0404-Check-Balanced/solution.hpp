#ifndef CHECK_BALANCED_20210325
#define CHECK_BALANCED_20210325

struct Node {
    int key;
    Node* left;
    Node* right;
};

/**
 * Implement a function to check if a binary tree is balanced.
 * For the purpose of this question, a balanced tree is defined
 * to be a tree such that the heights of the two subtrees of any 
 * node never diff by more than one.
 */
class Tree {
public:
    void set_root(Node* node) { m_root = node; }

    bool check_balanced();

private:
    Node* m_root;
};

#endif