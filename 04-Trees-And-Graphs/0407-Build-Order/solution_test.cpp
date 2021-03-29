#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(Build_Order, basic)
{
    std::vector<Work::Project> projects{'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<std::pair<Work::Project, Work::Project>> dependencies{
        {'a', 'd'},
        {'f', 'b'},
        {'b', 'd'},
        {'f', 'a'},
        {'d', 'c'},
    };
    Work work{projects, dependencies};

    std::vector<Work::Project> expect{'f', 'e', 'b', 'a', 'd', 'c'};
    auto result = work.build_order();

    ASSERT_EQ(result.size(), expect.size());
    auto rit = result.begin();
    auto eit = expect.begin();
    for (; rit != result.end(); ++rit, ++eit) {
        EXPECT_EQ(*rit, *eit);
    }
}