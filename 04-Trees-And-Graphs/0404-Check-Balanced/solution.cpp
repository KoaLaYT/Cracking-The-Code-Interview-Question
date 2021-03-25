#include "solution.hpp"

#include <algorithm>
#include <cmath>

static int check_height(Node* node)
{
    if (!node) return 0;

    int left = check_height(node->left);
    if (left < 0) return -1;
    int right = check_height(node->right);
    if (right < 0) return -1;

    if (std::abs(left - right) > 1) return -1;
    return std::max(left, right) + 1;
}

bool Tree::check_balanced()
{
    return check_height(m_root) >= 0;
}