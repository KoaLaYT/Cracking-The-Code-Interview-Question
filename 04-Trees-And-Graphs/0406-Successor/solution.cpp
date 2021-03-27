#include "solution.hpp"

Node* Tree::search(int key)
{
    Node* node = m_root;
    while (node && key != node->key) {
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

static Node* min(Node* node)
{
    if (!node) return nullptr;
    while (node->left) {
        node = node->left;
    }
    return node;
}

Node* Tree::minimum() { return min(m_root); }

Node* Tree::successor(Node* node)
{
    if (!node) return nullptr;

    if (node->right) {
        return min(node->right);
    }

    while (node->p && node->p->left != node) {
        node = node->p;
    }
    return node->p;
}