#include "solution.hpp"

void Tree::free(Node* node)
{
    if (!node) return;
    free(node->left);
    free(node->right);
    delete node;
}

static Node* build(std::vector<int>& sorted, int lo, int hi)
{
    if (lo > hi) return nullptr;

    int mi = lo + (hi - lo) / 2;
    Node* node = new Node{sorted[mi]};
    node->left = build(sorted, lo, mi - 1);
    node->right = build(sorted, mi + 1, hi);
    return node;
}

Tree::Tree(std::vector<int>& sorted)
{
    m_root = build(sorted, 0, sorted.size() - 1);
}