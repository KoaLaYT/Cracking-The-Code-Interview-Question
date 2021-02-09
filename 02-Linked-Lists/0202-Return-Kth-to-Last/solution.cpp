/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-09 11:53:45 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-09 12:19:13
 */

#include "solution.hpp"

#include <cassert>
#include <cstdio>

/**
 * ASSUME:
 *      1. k = 1 means last element
 *      2. if list.length() < k, return first element
 *      3. list can not be empty
 */
std::list<int>::iterator kth_to_last(std::list<int>& list, int k)
{
    assert(!list.empty());

    auto result = list.begin();
    auto pioneer = list.begin();

    while (k-- > 0 && ++pioneer != list.end()) {
        // continue
    }

    while (pioneer != list.end()) {
        pioneer++;
        result++;
    }

    return result;
}