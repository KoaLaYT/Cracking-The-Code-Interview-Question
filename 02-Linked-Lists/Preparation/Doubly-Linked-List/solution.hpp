/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-06 21:44:19 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-06 22:24:48
 */

#ifndef DOUBLY_LINKED_LIST_20200206
#define DOUBLY_LINKED_LIST_20200206

struct Node {
    Node* prev{nullptr};
    Node* next{nullptr};
    // for simplicity, not using template
    int key;

    explicit Node(int k) : key{k} {}
};

struct DoublyLinkedList {
    Node* head{nullptr};
    Node* tail{nullptr};

    ~DoublyLinkedList()
    {
        Node* it = head;
        while (it) {
            Node* tmp = it->next;
            delete it;
            it = tmp;
        }
    }

    Node* search(int target);
    void insert(int target);
    Node* remove(int target);
};

#endif