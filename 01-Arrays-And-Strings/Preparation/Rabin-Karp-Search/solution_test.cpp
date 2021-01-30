#include "solution.hpp"

#include <gtest/gtest.h>

TEST(Rabin_Karp_Search, basic)
{
    struct Case {
        std::string pattern;
        std::string text;
        std::vector<size_t> expects;
    };

    std::vector<Case> cases{
        {{"AABA"}, {"AABAACAADAABAABA"}, {0, 9, 12}},
        {{"Geek"}, {"Geeks for Geeks"}, {0, 10}},
        {{"AAA"}, {"AAAAAA"}, {0, 1, 2, 3}},
    };

    for (const auto& c : cases) {
        auto result = search(c.pattern, c.text);

        ASSERT_EQ(result.size(), c.expects.size());

        for (int i = 0; i < result.size(); ++i) {
            EXPECT_EQ(result[i], c.expects[i]);
        }
    }
}