/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-03 23:07:34 
 * @Last Modified by: KoaLaYT
 * @Last Modified time: 2021-02-04 10:21:19
 */

#ifndef ROTATE_MATRIX_20200203
#define ROTATE_MATRIX_20200203

#include <array>

template <size_t N>
void swap(std::array<int, N * N>& matrix, int i, int j, int ii, int jj)
{
    int tmp = matrix[i * N + j];
    matrix[i * N + j] = matrix[ii * N + jj];
    matrix[ii * N + jj] = tmp;
}

/**
 * Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
 * write a method to rotate the image by 90 degree.
 */
template <size_t N>
void rotate_matrix(std::array<int, N * N>& matrix)
{
    for (int i = 0; i < N / 2; ++i) {
        for (int j = 0; j < N - 2 * i - 1; ++j) {
            swap<N>(matrix, i, j + i, j + i, N - i - 1);          // top right
            swap<N>(matrix, i, j + i, N - i - 1, N - j - i - 1);  // bottom right
            swap<N>(matrix, i, j + i, N - j - i - 1, i);          // bottom left
        }
    }
}

#endif