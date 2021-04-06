#include "solution.hpp"

namespace impl {

static Node* insert(Node* node, int key)
{
    if (!node) return new Node{key};
    node->size += 1;
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

static Node* nth_node(Node* node, int n)
{
    if (!node) return node;

    int left_size = node->left ? node->left->size : 0;
    if (left_size + 1 == n) {
        return node;
    } else if (left_size >= n) {
        return nth_node(node->left, n);
    } else {
        return nth_node(node->right, n - left_size - 1);
    }
}

};  // namespace impl

void Tree::insert(int key)
{
    m_root = impl::insert(m_root, key);
}

Node* Tree::random_node()
{
    std::uniform_int_distribution<> distrib{1, m_root->size};
    return impl::nth_node(m_root, distrib(m_gen));
}