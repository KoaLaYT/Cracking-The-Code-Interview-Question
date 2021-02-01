/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-01 22:36:00 
 * @Last Modified by:   KoaLaYT 
 * @Last Modified time: 2021-02-01 22:36:00 
 */

#include "solution.hpp"

#include <map>

static bool impl_by_map(const std::string& input);

static bool impl_by_bit_vector(const std::string& input);

/**
 * ASSUME input consists by ASCII, 
 * and palindrome is case insensitive, only alpha counts
 */
bool is_palindrome_permutation(const std::string& input)
{
    // return impl_by_map(input);
    return impl_by_bit_vector(input);
}

// ======================
// IMPLEMENTATION DETAILS
// ======================
static char to_lower(char c)
{
    if (c >= 'a' && c <= 'z') {
        return c;
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    } else {
        return '\0';
    }
}

bool impl_by_map(const std::string& input)
{
    std::map<char, int> record;
    int odds = 0;

    for (char c : input) {
        c = to_lower(c);
        if (!c) continue;

        if (record.find(c) == record.end()) {
            record[c] = 0;
        }
        record[c] += 1;

        if (record[c] % 2 == 1) {
            odds++;
        } else {
            odds--;
        }
    }

    return odds < 2;
}

bool impl_by_bit_vector(const std::string& input)
{
    int bit_vec = 0;

    for (char c : input) {
        c = to_lower(c);
        if (!c) continue;

        bit_vec ^= (1 << c);
    }

    return bit_vec == 0 || ((bit_vec - 1) & bit_vec) == 0;
}