#ifndef LOOP_DETECTION_20210219
#define LOOP_DETECTION_20210219

struct Node {
    int val;
    Node* next;

    explicit Node(int v) : val{v}, next{nullptr} {}
};

/**
 * Given a circular linked list, implement an algorithm that return the nodes
 * at the beginning of the loop.
 * 
 * DEFINITION:
 * Circular linked list: A (corrupt) linked list in which a node's next
 * pointer points to an earlier node, so as to make a loop in the list.
 * 
 * EXAMPLE:
 * Input: A -> B -> C -> D -> E -> F -> C
 * Output: C
 */
Node* loop_detect(Node* root);

#endif