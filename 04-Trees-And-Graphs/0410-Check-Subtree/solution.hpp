#ifndef CHECK_SUBTREE_20210401
#define CHECK_SUBTREE_20210401

struct Node {
    int key;
    Node* left;
    Node* right;

    explicit Node(int k) : key{k},
                           left{nullptr},
                           right{nullptr}
    {}
};

/**
 * T1 and T2 are two very large binary trees, with T1 much bigger than T2.
 * Create an algorithm to determine if T2 is a subtree of T1.
 * A tree T2 is a subtree of T1 if there exists a node n in T1 such that the
 * subtree of n is identical to T2. That is, if you cut off the tree at node 
 * n, the two trees will be identical.
 */
bool is_subtree(Node* t1, Node* t2);

#endif