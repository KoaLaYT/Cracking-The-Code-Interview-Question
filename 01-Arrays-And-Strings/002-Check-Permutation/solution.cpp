#include "solution.hpp"

#include <map>

bool check_permutation(const std::string& first, const std::string& second)
{
    // fast check
    if (first.length() != second.length()) return false;

    std::map<char, int> first_chars;

    // map all chars of the first string to its occurance
    for (char c : first) {
        if (first_chars.find(c) == first_chars.end()) {
            first_chars[c] = 0;
        }
        first_chars[c] += 1;
    }

    // iterate second string, check if exists in the map and the occurance is equal
    for (char c : second) {
        auto found = first_chars.find(c);

        if (found == first_chars.end() || found->second-- < 0) {
            return false;
        }
    }

    return true;
}