#include "solution.hpp"

#include <gtest/gtest.h>

#include <cstdio>
#include <vector>

TEST(Rotate_Matrix, basic)
{
    {
        std::array<int, 16> input{1, 2, 3, 4,
                                  5, 6, 7, 8,
                                  9, 10, 11, 12,
                                  13, 14, 15, 16};

        std::array<int, 16> expect{13, 9, 5, 1,
                                   14, 10, 6, 2,
                                   15, 11, 7, 3,
                                   16, 12, 8, 4};

        rotate_matrix<4>(input);

        for (int i = 0; i < 16; ++i) {
            EXPECT_EQ(input[i], expect[i]) << "Index: " << i;
        }
    }

    {
        std::array<int, 25> input{1, 2, 3, 4, 5,
                                  6, 7, 8, 9, 10,
                                  11, 12, 13, 14, 15,
                                  16, 17, 18, 19, 20,
                                  21, 22, 23, 24, 25};

        std::array<int, 25> expect{21, 16, 11, 6, 1,
                                   22, 17, 12, 7, 2,
                                   23, 18, 13, 8, 3,
                                   24, 19, 14, 9, 4,
                                   25, 20, 15, 10, 5};
        rotate_matrix<5>(input);

        for (int i = 0; i < 25; ++i) {
            EXPECT_EQ(input[i], expect[i]) << "Index: " << i;
        }
    }
}