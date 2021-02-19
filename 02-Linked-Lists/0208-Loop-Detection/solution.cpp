#include "solution.hpp"

// the input must be a circular list
Node* loop_detect(Node* root)
{
    Node* slow = root;
    Node* fast = root;

    do {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    } while (slow != fast);

    fast = root;

    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}