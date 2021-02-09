/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-09 10:47:47 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-09 11:15:57
 */

#include "solution.hpp"

#include <set>

void remove_dups(std::list<int>& list)
{
    if (list.empty()) return;

    std::set<int> uniques;
    for (auto it = list.cbegin(); it != list.cend(); ++it) {
        if (uniques.find(*it) != uniques.cend()) {
            list.erase(it);
        } else {
            uniques.insert(*it);
        }
    }
}