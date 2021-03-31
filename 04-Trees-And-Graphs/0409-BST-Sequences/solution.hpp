#ifndef BST_SEQUENCES_20210331
#define BST_SEQUENCES_20210331

#include <list>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;

    explicit Node(int k)
        : key{k},
          left{nullptr},
          right{nullptr}
    {}
};

/**
 * A binary search tree was created by traversing through an array
 * from left to right and inserting each element. Given a binary search
 * tree with distinct elements, print all possible arrays that could
 * have led to this tree.
 */
class Tree {
public:
    void set_root(Node* node) { m_root = node; }

    std::vector<std::list<int>> all_sequences();

private:
    Node* m_root;
};

#endif