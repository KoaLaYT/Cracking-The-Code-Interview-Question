#include "solution.hpp"

#include <limits>

static bool validate_bst(Node* node, int min, int max)
{
    if (!node) return true;

    if (node->key < min || node->key > max) return false;

    return validate_bst(node->left, min, node->key) &&
           validate_bst(node->right, node->key, max);
}

bool Tree::validate_bst()
{
    return ::validate_bst(m_root,
                          std::numeric_limits<int>::min(),
                          std::numeric_limits<int>::max());
}