/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-09 17:55:53 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-09 18:41:28
 */

#include "solution.hpp"

void SinglyLinkedList::swap(SinglyLinkedList&& list)
{
    head = list.head;
    list.head = nullptr;
}

void SinglyLinkedList::free()
{
    while (head != nullptr) {
        auto tmp = head->next;
        delete head;
        head = tmp;
    }
}

void delete_middle_node(SinglyLinkedList::Iterator mid)
{
    auto next = mid;
    ++next;

    *mid = *next;
    mid.current->next = next.current->next;
    delete next.current;
}