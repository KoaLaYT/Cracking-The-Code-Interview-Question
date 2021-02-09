#include "solution.hpp"

void urlify(std::array<char, SIZE>& str, size_t len)
{
    int spaces = 0;
    for (size_t i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            spaces++;
        }
    }

    if (spaces == 0) return;

    int index = len + spaces * 2;
    str[index--] = '\0';
    len--;
    while (index >= 0) {
        if (str[len] == ' ') {
            str[index] = '0';
            str[index - 1] = '2';
            str[index - 2] = '%';
            index -= 2;
        } else {
            str[index] = str[len];
        }
        index--;
        len--;
    }
}