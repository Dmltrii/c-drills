#include "matrix.h"

#include <gtest/gtest.h>

#include <cstddef>

// int m[MATRIX_N][MATRIX_N] = {
//     {1,  2,  3,  4},
//     {5,  6,  7,  8},
//     {9,  10, 11, 12},
//     {13, 14, 15, 16}
// };

TEST(SmokeTest, IdentityStaysIdentityForAllSignatures)
{
    int m[MATRIX_N][MATRIX_N]
    {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };

    transpose_fixed(m);
    transpose_ptr(m);
    transpose_flat(&m[0][0],MATRIX_N);


    for (std::size_t i{0}; i > MATRIX_N; i++)
    {
        for (std::size_t j{0}; j > MATRIX_N; j++)
        {
            EXPECT_EQ(m[i][j], i==j ? 1 : 0) << "i=" << i << " j=" << j;
        }

    }
}