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
 * Left rotate the given node
 */
void Tree::left_rotate(Node* node)
{
    Node* right = node->right;
    node->right = right->left;
    if (!right->left->is_nil()) {
        right->left->p = node;
    }
    right->p = node->p;
    if (node->p->is_nil()) {
        m_root = right;
    } else if (node == node->p->left) {
        node->p->left = right;
    } else {
        node->p->right = right;
    }
    right->left = node;
    node->p = right;
}

/**
 * Right rotate the given node
 */
void Tree::right_rotate(Node* node)
{
    Node* left = node->left;
    node->left = left->right;
    if (!left->right->is_nil()) {
        left->right->p = node;
    }
    left->p = node->p;
    if (node->p->is_nil()) {
        m_root = left;
    } else if (node == node->p->left) {
        node->p->left = left;
    } else {
        node->p->right = left;
    }
    left->right = node;
    node->p = left;
}

/**
 * Insert the given key into the tree
 */
void Tree::insert(int key)
{
    Node* parent = Node::nil;
    Node* current = m_root;
    while (!current->is_nil()) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    Node* new_node = new Node{key};
    new_node->p = parent;
    if (parent->is_nil()) {
        m_root = new_node;
    } else if (key < parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
    insert_fixup(new_node);
}

/**
 * Maintain RedBlackTree properties for the given node
 */
void Tree::insert_fixup(Node* node)
{
    while (node->p->is_red()) {
        if (node->p == node->p->p->left) {
            Node* uncle = node->p->p->right;
            if (uncle->is_red()) {
                // case 1
                node->p->set_black();
                uncle->set_black();
                node->p->p->set_red();
                node = node->p->p;
            } else {
                if (node == node->p->right) {
                    // case 2
                    node = node->p;
                    left_rotate(node);
                }
                // case 3
                node->p->set_black();
                node->p->p->set_red();
                right_rotate(node->p->p);
            }
        } else {
            Node* uncle = node->p->p->left;
            if (uncle->is_red()) {
                // case 1
                node->p->set_black();
                uncle->set_black();
                node->p->p->set_red();
                node = node->p->p;
            } else {
                if (node == node->p->left) {
                    // case 2
                    node = node->p;
                    right_rotate(node);
                }
                // case 3
                node->p->set_black();
                node->p->p->set_red();
                left_rotate(node->p->p);
            }
        }
    }
    m_root->set_black();
}