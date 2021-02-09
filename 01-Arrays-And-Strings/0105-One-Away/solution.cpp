/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-02 22:57:15 
 * @Last Modified by:   KoaLaYT 
 * @Last Modified time: 2021-02-02 22:57:15 
 */

#include "solution.hpp"

bool is_one_away(const std::string& s1, const std::string& s2)
{
    int len1 = s1.length();
    int len2 = s2.length();

    int diff = len1 - len2;

    if (diff < -1 || diff > 1) return false;

    auto iter1 = s1.begin();
    auto iter2 = s2.begin();
    bool has_find_diff = false;

    while (iter1 != s1.end() && iter2 != s2.end()) {
        if (*iter1 != *iter2) {
            if (has_find_diff) return false;
            has_find_diff = true;
            if (diff < 0) {
                // this is an insertion
                iter2++;
                continue;
            } else if (diff > 0) {
                // this is a removal
                iter1++;
                continue;
            }
        }
        // replacement OR equivalent
        iter1++;
        iter2++;
    }

    return true;
}