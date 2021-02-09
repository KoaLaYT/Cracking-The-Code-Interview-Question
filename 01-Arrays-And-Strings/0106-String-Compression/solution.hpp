/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-03 22:18:35 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-03 22:44:43
 */

#ifndef STRING_COMPRESSION_20200203
#define STRING_COMPRESSION_20200203

#include <string>

/**
 * Implement a method to perform basic string compression using the counts of 
 * repeated characters. For example, the string `aabcccccaaa` would become `a2blc5a3`.
 * If the "compressed" string would not become smaller than the origin string, 
 * your method should return the origin string.
 */
std::string string_compression(const std::string& input);

#endif