/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-05 22:03:37 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-05 22:20:57
 */

#ifndef STRING_ROTATION_20200205
#define STRING_ROTATION_20200205

#include <string>

/**
 * Check if s1 is a substring of s2
 */
static bool is_substring(const std::string& s1, const std::string& s2)
{
    auto it = s2.find(s1);
    return it != std::string::npos;
}

/**
 * Assume you have a method `is_substring` which checks if one word is a substring
 * of another. Given two strings s1 and s2, write code to check if s2 is a rotation
 * of s1 using only one call to `is_substring`.
 * 
 * Example:
 *      "waterbottle" is a rotation of" erbottlewat"
 */
bool is_rotation(const std::string& s1, const std::string& s2);

#endif