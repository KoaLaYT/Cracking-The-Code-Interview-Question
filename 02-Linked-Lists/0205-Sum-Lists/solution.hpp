/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-10 16:04:26 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-10 16:23:07
 */

#ifndef SUM_LISTS_20210210
#define SUM_LISTS_20210210

#include <list>

/**
 * You have two numbers represented by a linked list, where each node contain a 
 * single digit. The digits are stored in reverse order, such that the 1's digit
 * is at the head of the list. Write a function that adds two numbers and return
 * the sums as a linked list.
 * 
 * Example:
 *       Input: 7 -> 1 -> 6 + 5 -> 9 -> 2. That is, 617 + 295.
 *      Output: 2 -> 1 -> 9. That is, 912.
 */
std::list<int> sum_reverse_order(const std::list<int>& num1, const std::list<int>& num2);

/**
 * FOLLOW UP:
 * Suppose the digits are stored in forward order. Repeat the above problem.
 * 
 * Example:
 *       Input: 6 -> 1 -> 7 + 2 -> 9 -> 5. That is, 617 + 295. 
 *      Output: 9 -> 1 -> 2. That is, 912.
 */
std::list<int> sum_forward_order(const std::list<int>& num1, const std::list<int>& num2);

#endif