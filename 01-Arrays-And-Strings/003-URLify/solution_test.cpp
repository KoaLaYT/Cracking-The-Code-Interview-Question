#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

struct Case {
    std::array<char, SIZE> str{};
    size_t len{0};
    const char* expect;

    Case(const char* input, const char* url)
        : expect{url}
    {
        size_t i = 0;
        while (*input) {
            str[i] = *input;
            i++;
            input++;
        }
        str[i + 1] = '\0';
        len = i;
    }
};

TEST(URLify, basic)
{
    std::vector<Case> cases{
        {"hello, world", "hello,%20world"},
        {"", ""},
        {"a b c ", "a%20b%20c%20"},
        {"abccba", "abccba"},
    };

    for (auto& c : cases) {
        urlify(c.str, c.len);

        size_t i = 0;
        while (c.expect[i]) {
            EXPECT_EQ(c.str[i], c.expect[i]) << "Index: " << i;
            i++;
        }
    }
}