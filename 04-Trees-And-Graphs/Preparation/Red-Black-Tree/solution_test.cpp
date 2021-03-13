#include "solution.hpp"

#include <gtest/gtest.h>

#include <queue>
#include <vector>

class TreeTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        Node* n5 = new Node{5};
        Node* n8 = new Node{8};
        Node* n7 = new Node{7};
        n7->color = Node::Color::Black;
        n5->p = n7;
        n8->p = n7;
        n7->left = n5;
        n7->right = n8;

        Node* n1 = new Node{1};
        n1->color = Node::Color::Black;
        Node* n2 = new Node{2};
        n1->p = n2;
        n7->p = n2;
        n2->left = n1;
        n2->right = n7;

        Node* n15 = new Node{15};
        Node* n14 = new Node{14};
        n14->color = Node::Color::Black;
        n15->p = n14;
        n14->right = n15;

        Node* root = new Node{11};
        root->color = Node::Color::Black;
        n2->p = root;
        n14->p = root;
        root->left = n2;
        root->right = n14;

        tree.set_root(root);
    }

    Tree tree;
};

/**
 * Check if a RedBlackTree maintain its properties
 * 
 * ✅ 1. Every node is either red or black.
 * 🔍 2. The root is black.
 * ✅ 3. Every leaf is black.
 * 🔍 4. If a node is red, then both its children are black.
 * 🔍 5. For each node, all simple paths from the node to descendant leaves contain
 *       the same number of black nodes.
 */
class RBPropertyChecker {
public:
    explicit RBPropertyChecker(Tree& t)
        : m_tree{t} {}

    bool property_maintained()
    {
        return root_black() &&
               red_children_all_black() &&
               equal_black();
    }
    // check property 2
    bool root_black() { return root()->color == Node::Color::Black; }
    // check property 4
    bool red_children_all_black() { return red_children_all_black(root()); }
    // check property 5
    bool equal_black() { return equal_black_recursive(root()); }

private:
    Tree& m_tree;

    Node* root() { return m_tree.get_root(); }

    bool red_children_all_black(Node* node);
    bool equal_black_recursive(Node* node);
    void equal_black(Node* node, int bh, std::vector<int>& bhs);
};

/**
 * Recursivly check property 4: 
 * If a node is red, then both its children are black.
 */
bool RBPropertyChecker::red_children_all_black(Node* node)
{
    if (node->is_nil()) return true;

    bool result = true;
    if (node->is_red()) {
        result = node->left->is_black() && node->right->is_black();
    }
    return result &&
           red_children_all_black(node->left) &&
           red_children_all_black(node->right);
}

/**
 * Recursivly check property 5:  
 * For each node, all simple paths from the node to descendant leaves contain
 * the same number of black nodes.
 */
bool RBPropertyChecker::equal_black_recursive(Node* node)
{
    if (node->is_nil()) return true;

    std::vector<int> bhs;
    equal_black(node, 0, bhs);
    for (int i = 1; i < bhs.size(); ++i) {
        if (bhs[i - 1] != bhs[i]) return false;
    }

    return equal_black_recursive(node->left) &&
           equal_black_recursive(node->right);
}

/**
 * Check if single node meet property 5
 */
void RBPropertyChecker::equal_black(Node* node, int bh, std::vector<int>& bhs)
{
    if (node->is_nil()) {
        bhs.push_back(bh);
        return;
    }
    if (node->is_black()) {
        ++bh;
    }
    equal_black(node->left, bh, bhs);
    equal_black(node->right, bh, bhs);
}

TEST_F(TreeTest, checker)
{
    RBPropertyChecker checker{tree};
    EXPECT_TRUE(checker.root_black());
    EXPECT_TRUE(checker.red_children_all_black());
    EXPECT_TRUE(checker.equal_black());
    EXPECT_TRUE(checker.property_maintained());
}

TEST_F(TreeTest, height)
{
    EXPECT_EQ(tree.height(), 4);
}

TEST_F(TreeTest, search)
{
    Node* found = tree.search(7);
    ASSERT_FALSE(found->is_nil());
    EXPECT_EQ(found->key, 7);
    EXPECT_TRUE(found->is_black());

    Node* not_found = tree.search(4);
    ASSERT_TRUE(not_found->is_nil());
}

TEST_F(TreeTest, insert)
{
    RBPropertyChecker checker{tree};
    int inserts[] = {4, 13, 12, 16, 17, 18, 3, 9, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    for (auto key : inserts) {
        tree.insert(key);
        ASSERT_FALSE(tree.search(key)->is_nil());
        EXPECT_TRUE(checker.property_maintained()) << "Insert key: " << key << " failed";
        EXPECT_TRUE(checker.root_black());
        EXPECT_TRUE(checker.red_children_all_black());
        EXPECT_TRUE(checker.equal_black());
    }
}