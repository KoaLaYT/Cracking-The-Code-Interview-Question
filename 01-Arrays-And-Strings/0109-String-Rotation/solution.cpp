#include "solution.hpp"

bool is_rotation(const std::string& s1, const std::string& s2)
{
    if (s1.length() != s2.length()) return false;

    return is_substring(s2, s1 + s1);
}