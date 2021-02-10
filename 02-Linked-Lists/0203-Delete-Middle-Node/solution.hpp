/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-09 17:55:28 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-09 18:45:24
 */

#ifndef DELETE_MIDDLE_NODE_20200203
#define DELETE_MIDDLE_NODE_20200203

#include <list>

struct Node {
    int data;
    Node* next;

    explicit Node(int d) : data{d}, next{nullptr} {}
};

struct SinglyLinkedList {
    Node* head;

    SinglyLinkedList(std::initializer_list<int> list) : head{nullptr} { copy_from(list); }
    ~SinglyLinkedList() { free(); }

    SinglyLinkedList(const SinglyLinkedList& list) : head{nullptr} { copy_from(list); }
    SinglyLinkedList& operator=(const SinglyLinkedList& list)
    {
        free();
        copy_from(list);
        return *this;
    }

    SinglyLinkedList(SinglyLinkedList&& list) { swap(std::move(list)); }
    SinglyLinkedList& operator=(SinglyLinkedList&& list)
    {
        swap(std::move(list));
        return *this;
    }

    struct Iterator {
        Node* current;

        Iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const { return other.current != current; }
        bool operator==(const Iterator& other) const { return !(*this != other); }

        int& operator*() { return current->data; }
    };

    Iterator begin() const { return Iterator{head}; }
    Iterator end() const { return Iterator{nullptr}; }

private:
    template <typename T>
    void copy_from(T& list)
    {
        Node* current = head;
        for (auto it = list.begin(); it != list.end(); ++it) {
            Node* node = new Node{*it};
            if (current) {
                current->next = node;
            } else {
                head = node;
            }
            current = node;
        }
    }

    void swap(SinglyLinkedList&& list);

    void free();
};

/**
 * Implement an algorithm to delete a node in the middle
 * (i.e., any node but first or last node, not necessarily
 * the exact middle) of a singly linked list, given access
 * only to that node.
 */
void delete_middle_node(SinglyLinkedList::Iterator mid);

#endif