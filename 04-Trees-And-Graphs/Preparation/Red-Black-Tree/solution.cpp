#include "solution.hpp"

#include <queue>

/**
 * Define a nil node for simplifying code
 */
static Node* make_nil()
{
    Node* n = new Node{0};
    n->color = Node::Color::Black;
    return n;
}

Node* Node::nil = make_nil();

/**
 * Height of the given subtree
 */
int Tree::height(Node* node)
{
    if (node->is_nil()) return 0;

    std::queue<Node*> q;
    q.push(node);
    int h = 0;
    while (!q.empty()) {
        ++h;
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            auto first = q.front();
            if (!first->left->is_nil()) q.push(first->left);
            if (!first->right->is_nil()) q.push(first->right);
            q.pop();
        }
    }
    return h;
}

/**
 * Free nodes' memory
 */
void Tree::free(Node* node)
{
    if (node->is_nil()) return;
    free(node->left);
    free(node->right);
    delete node;
}

/**
 * Search in the tree for the given key
 */
Node* Tree::search(int key)
{
    Node* node = m_root;
    while (!node->is_nil() && node->key != key) {
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

/**
 * Insert the given key into the tree
 */
void Tree::insert(int key)
{
}