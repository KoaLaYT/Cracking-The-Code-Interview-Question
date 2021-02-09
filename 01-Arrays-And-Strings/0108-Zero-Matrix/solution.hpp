/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-04 21:50:36 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-04 22:56:22
 */

#ifndef ZERO_MATRIX_20200204
#define ZERO_MATRIX_20200204

#include <array>
#include <set>

/**
 * Using two set to record rows and cols that have zeros
 * Spacing: O(N)
 * Timing: O(NM)
 */
template <size_t N, size_t M>
static void impl_by_set(std::array<int, N * M>& matrix);

/**
 * Using first row and first col to record zero rows and cols
 * Spacing: O(1)
 * Timing: O(NM)
 */
template <size_t N, size_t M>
static void impl_by_inplace_record(std::array<int, N * M>& matrix);

/**
 * Write an algorithm such that if an element in an M x N matrix is 0, its entire row
 * and column are set to 0.
 */
template <size_t N, size_t M>
void zero_matrix(std::array<int, N * M>& matrix)
{
    if (matrix.size() == 0) return;
    // impl_by_set<N, M>(matrix);
    impl_by_inplace_record<N, M>(matrix);
}

// ======================
// IMPLEMENTATION DETAILS
// ======================
template <size_t N, size_t M>
void impl_by_set(std::array<int, N * M>& matrix)
{
    std::set<size_t> zero_rows;
    std::set<size_t> zero_cols;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (matrix[i * M + j] == 0) {
                zero_rows.insert(i);
                zero_cols.insert(j);
            }
        }
    }

    for (auto it = zero_rows.begin(); it != zero_rows.end(); ++it) {
        for (int j = 0; j < M; ++j) {
            matrix[*it * M + j] = 0;
        }
    }

    for (auto it = zero_cols.begin(); it != zero_cols.end(); ++it) {
        for (int i = 0; i < N; ++i) {
            matrix[i * M + *it] = 0;
        }
    }
}

template <size_t N, size_t M>
void impl_by_inplace_record(std::array<int, N * M>& matrix)
{
    bool first_row_has_zero = false;
    bool first_col_has_zero = false;

    // check if first row has zero
    for (int j = 0; j < M; ++j) {
        if (matrix[j] == 0) {
            first_row_has_zero = true;
            break;
        }
    }

    // check if first col has zero
    for (int i = 0; i < N; ++i) {
        if (matrix[i * M] == 0) {
            first_col_has_zero = true;
            break;
        }
    }

    // check rest matrix, and record zero info in first row and col
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            if (matrix[i * M + j] == 0) {
                matrix[i * M] = 0;
                matrix[j] = 0;
            }
        }
    }

    // write zero rows
    for (int i = 1; i < N; ++i) {
        if (matrix[i * M] == 0) {
            for (int j = 1; j < M; ++j) {
                matrix[i * M + j] = 0;
            }
        }
    }

    // write zero cols
    for (int j = 1; j < M; ++j) {
        if (matrix[j] == 0) {
            for (int i = 1; i < N; ++i) {
                matrix[i * M + j] = 0;
            }
        }
    }

    // write first row
    if (first_row_has_zero) {
        for (int j = 0; j < M; ++j) {
            matrix[j] = 0;
        }
    }

    // write first col
    if (first_col_has_zero) {
        for (int i = 0; i < N; ++i) {
            matrix[i * M] = 0;
        }
    }
}

#endif