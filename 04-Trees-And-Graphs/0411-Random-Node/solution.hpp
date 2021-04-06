#ifndef RANDOM_NODE_20210402
#define RANDOM_NODE_20210402

#include <random>

struct Node {
    int key;
    int size;
    Node* left;
    Node* right;

    explicit Node(int k) : key{k},
                           size{1},
                           left{nullptr},
                           right{nullptr}
    {}
};

/**
 * You are implementing a binary search tree class from scratch, which, in addition
 * to `insert`, `find` and `delete`, has a method `getRandomNode` which returns a 
 * random node from the tree. All nodes should be equally likely to be chosen. Design
 * and implement an algorithm for `getRandomNode`, and explain how you would implement
 * the rest of the methods.
 */
class Tree {
public:
    Tree() : m_root{nullptr}
    {
        std::random_device rd;
        m_gen = std::mt19937{rd()};
    }

    Node* random_node();

    void insert(int key);

    int size() { return m_root->size; }

private:
    Node* m_root;
    std::mt19937 m_gen;
};

#endif