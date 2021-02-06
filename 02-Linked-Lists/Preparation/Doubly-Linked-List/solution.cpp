#include "solution.hpp"

Node* DoublyLinkedList::search(int target)
{
    Node* it = head;
    while (it) {
        if (it->key == target)
            return it;
        it = it->next;
    }
    return nullptr;
}

// ASSUME: no duplicate target
void DoublyLinkedList::insert(int target)
{
    Node* node = new Node{target};
    node->next = head;
    if (head) {
        head->prev = node;
    }
    head = node;

    if (!tail) {
        tail = node;
    }
}

Node* DoublyLinkedList::remove(int target)
{
    Node* it = search(target);
    if (!it) return nullptr;

    // remove head
    if (!it->prev) {
        head = it->next;
        if (!head) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        it->next = nullptr;
    }
    // remove tail
    else if (!it->next) {
        tail = it->prev;
        if (!tail) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        it->prev = nullptr;
    }
    // remove middle node
    else {
        it->prev->next = it->next;
        it->next->prev = it->prev;

        it->next = nullptr;
        it->prev = nullptr;
    }

    return it;
}