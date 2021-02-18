#ifndef INTERSECTION_20210218
#define INTERSECTION_20210218

#include <list>

// Fake list node
struct Node {
    int some_val;
    int other_val;
};

/**
 * Given two (singly) linked lists, determine if the two lists intersect, return the 
 * intersecting node. Note the intersection is defined based on reference, not value.
 * That is, if the kth node of the first list is the exact node (by reference) as the
 * jth node of the second list, then they are intersecting.
 */
Node* intersection(const std::list<Node*>& list1, const std::list<Node*>& list2);

#endif