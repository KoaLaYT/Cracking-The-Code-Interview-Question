/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-10 10:25:11 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-10 11:16:52
 */

#include "solution.hpp"

void partition(std::list<int>& list, int pivot)
{
    auto it = list.cbegin();
    auto end = list.cend();
    std::advance(end, -1);  // pointing to the end of list

    while (it != end) {
        int value = *it;
        if (value >= pivot) {
            it = list.erase(it);
            list.push_back(value);
        } else {
            ++it;
        }
    }

    // we don't need to move last element, whether it's bigger or less than the pivot,
    // it is always in the right position.
}