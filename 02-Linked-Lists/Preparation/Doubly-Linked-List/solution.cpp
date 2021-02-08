#include "solution.hpp"

Node* DoublyLinkedList::search(int target)
{
    Node* it = head();
    while (it != m_nil && it->key != target) {
        it = it->next;
    }
    return it;
}

// ASSUME: no duplicate target
void DoublyLinkedList::insert(int target)
{
    Node* node = new Node{target};
    node->prev = m_nil;
    node->next = head();
    head()->prev = node;
    m_nil->next = node;
}

Node* DoublyLinkedList::remove(int target)
{
    Node* it = search(target);
    if (it != m_nil) {
        it->prev->next = it->next;
        it->next->prev = it->prev;

        it->next = nullptr;
        it->prev = nullptr;
    }
    return it;
}