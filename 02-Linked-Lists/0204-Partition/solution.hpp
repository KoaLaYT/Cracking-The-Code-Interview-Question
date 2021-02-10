/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-10 10:25:08 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-10 10:33:21
 */

#ifndef PARTITION_20200210
#define PARTITION_20200210

#include <list>

/**
 * Write code to partition a linked list around a value `x`, such that all
 * value less than `x` come before all nodes greater than or equal to `x`.
 * If `x` is contained within the list, the values of `x` only need to be
 * after the elements less than `x`. The partition element `x` can appear 
 * anywhere in "right partition"; it does not need to appear between the left
 * and right partitions.
 */
void partition(std::list<int>& list, int pivot);

#endif