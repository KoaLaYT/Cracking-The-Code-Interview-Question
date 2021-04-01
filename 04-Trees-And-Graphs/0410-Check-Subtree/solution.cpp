#include "solution.hpp"

static bool is_same(Node* t1, Node* t2)
{
    if (!t1 && !t2) return true;
    if (t1->key != t2->key) return false;
    return is_same(t1->left, t2->left) && is_same(t1->right, t2->right);
}

// t2 will never be nullptr
static bool check(Node* t1, Node* t2)
{
    if (!t1) return false;
    if (t1->key == t2->key) {
        bool same = is_same(t1, t2);
        if (same) return true;
    }
    return check(t1->left, t2) || check(t1->right, t2);
}

bool is_subtree(Node* t1, Node* t2)
{
    if (!t2) return true;
    return check(t1, t2);
}