#include "solution.hpp"

Node* intersection(const std::list<Node*>& list1, const std::list<Node*>& list2)
{
    int len1 = 0;
    int len2 = 0;
    auto it1 = list1.cbegin();
    auto it2 = list2.cbegin();

    while (it1 != list1.cend() || it2 != list2.cend()) {
        if (it1 != list1.cend()) {
            len1++;
            it1++;
        }
        if (it2 != list2.cend()) {
            len2++;
            it2++;
        }
    }

    if (*--it1 != *--it2) return nullptr;

    int diff = len1 - len2;
    it1 = list1.cbegin();
    it2 = list2.cbegin();
    while (diff < 0) {
        it2++;
        diff++;
    }
    while (diff > 0) {
        it1++;
        diff--;
    }

    while (*it1 != *it2) {
        it1++;
        it2++;
    }

    return *it1;
}