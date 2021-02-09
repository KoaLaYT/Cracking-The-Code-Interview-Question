/*
 * @Author: KoaLaYT 
 * @Date: 2021-01-31 13:56:42 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-01-31 14:27:51
 */

#include "solution.hpp"

#include <bitset>
#include <set>

/**
 * *ASSUME this is an ASCII string*
 * Use a set to record all appeared characters
 */
static bool is_unique_impl_set(const std::string& str);

/**
 * We can just use a boolean array to do record, every char map to index
 */
static bool is_unique_impl_array(const std::string& str);

/**
 * We can reduce the space usage by a factor of 8, by using bitset!
 */
static bool is_unique_impl_bitset(const std::string& str);

bool is_unique(const std::string& str)
{
    // return is_unique_impl_set(str);
    // return is_unique_impl_array(str);
    return is_unique_impl_bitset(str);
}

// ======================
// IMPLEMENTATION DETAILS
// ======================
bool is_unique_impl_set(const std::string& str)
{
    std::set<char> record;

    for (char c : str) {
        if (record.find(c) != record.end()) {
            return false;
        }
        record.insert(c);
    }

    return true;
}

bool is_unique_impl_array(const std::string& str)
{
    bool record[128] = {};  // Initialize all slots to false

    for (char c : str) {
        if (record[c]) {
            return false;
        }
        record[c] = true;
    }

    return true;
}

static bool is_unique_impl_bitset(const std::string& str)
{
    std::bitset<128> record;

    for (char c : str) {
        if (record[c]) {
            return false;
        }
        record[c] = true;
    }

    return true;
}