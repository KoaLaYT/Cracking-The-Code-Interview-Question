/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-06 21:44:19 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-08 12:23:14
 */

#ifndef DOUBLY_LINKED_LIST_20200206
#define DOUBLY_LINKED_LIST_20200206

struct Node {
    Node* prev{nullptr};
    Node* next{nullptr};
    // for simplicity, not using template
    int key;

    explicit Node(int k) : key{k} {}

    static Node* create_nil()
    {
        Node* nil = new Node{0};
        nil->prev = nil;
        nil->next = nil;
        return nil;
    }
};

struct DoublyLinkedList {
    DoublyLinkedList() : m_nil{Node::create_nil()} {}

    ~DoublyLinkedList()
    {
        Node* it = head();
        while (it != m_nil) {
            Node* tmp = it->next;
            delete it;
            it = tmp;
        }
    }

    Node* head() { return m_nil->next; }
    Node* tail() { return m_nil->prev; }
    Node* nil() { return m_nil; }

    Node* search(int target);
    void insert(int target);
    Node* remove(int target);

private:
    Node* m_nil;
};

#endif