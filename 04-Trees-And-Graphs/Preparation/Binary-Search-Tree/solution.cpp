#include "solution.hpp"

#include <queue>

namespace BinarySearchTree {
/**
 * Get the height of the subtree
 */
int Tree::height(Node* node)
{
    if (!node) return 0;

    std::queue<Node*> q;
    int h = 0;
    q.push(node);
    while (!q.empty()) {
        ++h;
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            auto first = q.front();
            if (first->left) q.push(first->left);
            if (first->right) q.push(first->right);
            q.pop();
        }
    }
    return h;
}

/**
 * Search from the given node,
 * return a pointer to a node with key if one exists,
 * otherwise nullptr.
 */
Node* Tree::search(Node* node, int key)
{
    while (node && node->key != key) {
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

/**
 * Find the minimum node from the given node.
 */
Node* Tree::minimum(Node* node)
{
    if (!node) return node;
    while (node->left) {
        node = node->left;
    }
    return node;
}

/**
 * Find the maximum node from the given node.
 */
Node* Tree::maximum(Node* node)
{
    if (!node) return node;
    while (node->right) {
        node = node->right;
    }
    return node;
}

/**
 * Find the successor node of the given node, 
 * or nullptr if it is the maximum node.
 */
Node* Tree::successor(Node* node)
{
    if (!node) return node;
    if (node->right) {
        return minimum(node->right);
    }
    auto parent = node->p;
    while (parent && parent->right == node) {
        node = parent;
        parent = parent->p;
    }
    return parent;
}

/**
 * Find the prdecessor node of the given node,
 * or nullptr if it is the minimum node.
 */
Node* Tree::predecessor(Node* node)
{
    if (!node) return node;
    if (node->left) {
        return maximum(node->left);
    }
    auto parent = node->p;
    while (parent && parent->left == node) {
        node = parent;
        parent = parent->p;
    }
    return parent;
}

/**
 * Insert a new node into the tree.
 * Assume no duplicate keys.
 */
void Tree::insert(int key)
{
    Node* parent = nullptr;
    auto node = m_root;
    while (node) {
        parent = node;
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    Node* new_node = new Node{key};
    new_node->p = parent;

    if (!parent) {
        m_root = new_node;
    } else if (key < parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

/**
 * Remove a node of the tree
 */
void Tree::remove(int key)
{
    Node* node = search(key);
    if (!node) return;

    if (!node->left) {
        transplant(node, node->right);
    } else if (!node->right) {
        transplant(node, node->left);
    } else {
        Node* replace = minimum(node->right);
        if (replace->p != node) {
            transplant(replace, replace->right);
            replace->right = node->right;
            replace->right->p = replace;
        }
        transplant(node, replace);
        replace->left = node->left;
        replace->left->p = replace;
    }

    delete node;
}

/**
 * Move node b to replace node a
 */
void Tree::transplant(Node* a, Node* b)
{
    if (!a->p) {
        m_root = b;
    } else if (a->p->left == a) {
        a->p->left = b;
    } else {
        a->p->right = b;
    }
    if (b) {
        b->p = a->p;
    }
}

/**
 * Recursivly free the nodes of the subtree
 */
void Tree::free(Node* node)
{
    if (!node) return;
    free(node->left);
    free(node->right);
    delete node;
}

}