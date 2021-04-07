#ifndef PATHS_WITH_SUM_20210407
#define PATHS_WITH_SUM_20210407

/**
 * You are given a binary tree in which each node contains an integer value
 * (which might positive or negative). Design an algorithm to count the number
 * of paths that sum to a given value. The path does not need to start or end
 * at the root or a leaf, but it must go downwards (traveling only from parent 
 * nodes to child nodes).
 */
struct Node {
    int value;
    Node* left;
    Node* right;

    explicit Node(int v) : value{v},
                           left{nullptr},
                           right{nullptr}
    {}
};

int path_with_sum(Node* root, int sum);

#endif