#ifndef URLIFY_20200131
#define URLIFY_20200131

#include <array>

constexpr size_t SIZE = 1024;

/**
 * Write a method to replace all spaces in a string with '%20'.
 * You may assume that the string has sufficient space at the end
 * to hold the additional characters, and that you are given the "true"
 * length of the string.
 */
void urlify(std::array<char, SIZE>& str, size_t len);

#endif