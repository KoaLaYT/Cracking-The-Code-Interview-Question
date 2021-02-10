/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-10 16:04:29 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-10 17:03:05
 */

#include "solution.hpp"

std::list<int> sum_reverse_order(const std::list<int>& num1, const std::list<int>& num2)
{
    std::list<int> result;

    auto it1 = num1.cbegin();
    auto it2 = num2.cbegin();
    int carry = 0;

    while (it1 != num1.cend() || it2 != num2.cend()) {
        int value = carry;

        if (it1 != num1.cend()) value += *it1++;
        if (it2 != num2.cend()) value += *it2++;

        carry = value >= 10 ? 1 : 0;

        result.push_back(value % 10);
    }

    if (carry > 0) result.push_back(carry);

    return result;
}

// Recursivly push caclucated sum into result, and return carry back
static int sum_forward_recursion(std::list<int>::const_iterator it1, std::list<int>::const_iterator it2,
                                 std::list<int>::const_iterator end1, std::list<int>& result);

// Padding zeros to shorter list, making two lists same length
static void padding_zeros(std::list<int>& num1, std::list<int>& num2);

// Assume the list is singly linked
std::list<int> sum_forward_order(const std::list<int>& num1, const std::list<int>& num2)
{
    std::list<int> result;

    auto copy1{num1};
    auto copy2{num2};
    padding_zeros(copy1, copy2);

    int carry = sum_forward_recursion(copy1.cbegin(), copy2.cbegin(), copy1.cend(), result);
    if (carry > 0) result.push_front(carry);

    return result;
}

static void padding_zeros(std::list<int>& num1, std::list<int>& num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    int diff = len1 - len2;
    while (diff < 0) {
        num1.push_front(0);
        diff++;
    }
    while (diff > 0) {
        num2.push_front(0);
        diff--;
    }
}

static int sum_forward_recursion(std::list<int>::const_iterator it1, std::list<int>::const_iterator it2,
                                 std::list<int>::const_iterator end1, std::list<int>& result)
{
    if (it1 == end1) return 0;

    int sum = *it1++ + *it2++;
    sum += sum_forward_recursion(it1, it2, end1, result);
    result.push_front(sum % 10);
    return sum >= 10 ? 1 : 0;
}