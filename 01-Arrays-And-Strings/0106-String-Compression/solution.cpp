/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-03 22:38:09 
 * @Last Modified by:   KoaLaYT 
 * @Last Modified time: 2021-02-03 22:38:09 
 */

#include "solution.hpp"

static void append_num_char(std::string& str, char c, int num)
{
    if (num) {
        str.append(1, c);
        str.append(std::to_string(num));
    }
}

std::string string_compression(const std::string& input)
{
    std::string compressed;
    char current = '\0';
    int count = 0;

    for (char c : input) {
        if (c != current) {
            append_num_char(compressed, current, count);
            current = c;
            count = 0;
        }
        count += 1;
    }
    append_num_char(compressed, current, count);

    return compressed.length() < input.length() ? compressed : input;
}