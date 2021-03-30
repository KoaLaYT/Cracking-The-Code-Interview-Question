#include "solution.hpp"

static int depth(Node* node)
{
    int result = 0;
    while (node && node->p) {
        result++;
        node = node->p;
    }
    return result;
}

Node* Tree::first_common_ancestor(Node* a, Node* b)
{
    if (!a || !b) return nullptr;

    int da = depth(a);
    int db = depth(b);

    int diff = da - db;
    while (diff > 0) {
        a = a->p;
        diff--;
    }
    while (diff < 0) {
        b = b->p;
        diff++;
    }

    while (a != b) {
        a = a->p;
        b = b->p;
    }

    return a;
}

static Node* find(Node* node, int key)
{
    if (!node || node->key == key) return node;
    Node* left = find(node->left, key);
    if (left) return left;
    return find(node->right, key);
}

Node* Tree::find(int key) { return ::find(m_root, key); }