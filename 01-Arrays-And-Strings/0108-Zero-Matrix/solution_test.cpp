/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-04 21:52:06 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-04 22:50:53
 */

#include "solution.hpp"

#include <gtest/gtest.h>

template <size_t N, size_t M>
struct Case {
    std::array<int, N * M> matrix;
    std::array<int, N * M> expect;

    void check()
    {
        zero_matrix<N, M>(matrix);
        for (int i = 0; i < matrix.size(); ++i) {
            EXPECT_EQ(matrix[i], expect[i]) << "Index: " << i;
        }
    }
};

TEST(Zero_Matrix, basic)
{
    Case<5, 4> c1{
        // clang-format off
        {
            1,  2,  3,  4,
            6,  7,  0,  9,
           11, 12, 13, 14,
           16, 17, 18, 19,
           20, 21, 22, 23,
        },
        {
            1,  2,  0,  4,
            0,  0,  0,  0,
           11, 12,  0, 14,
           16, 17,  0, 19,
           20, 21,  0, 23,
        },
        // clang-format on
    };
    c1.check();

    Case<5, 5> c2{
        // clang-format off
        {
            1,  2,  3,  4, 1,
            6,  0,  0,  9, 2,
           11, 12, 13,  0, 3,
           16, 17, 18, 19, 4,
           20, 21, 22,  0, 5,
        },
        {
            1,  0,  0,  0, 1,
            0,  0,  0,  0, 0,
            0,  0,  0,  0, 0,
           16,  0,  0,  0, 4,
            0,  0,  0,  0, 0,
        },
        // clang-format on
    };
    c2.check();
}