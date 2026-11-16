#include "matrix.h"

#include <gtest/gtest.h>

#include <cstddef>
#include <cstring>
#include <vector>

namespace
{
struct FlatCase
{
    std::size_t width;
    std::vector<int> input;
    std::vector<int> expected;
};
// clang-format off
constexpr int kInput[MATRIX_N][MATRIX_N]{
    {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9,  10, 11, 12},
    {13, 14, 15, 16},
};

constexpr int kTransposed[MATRIX_N][MATRIX_N]{
    {1, 5, 9,  13},
    {2, 6, 10, 14},
    {3, 7, 11, 15},
    {4, 8, 12, 16},
};
// clang-format on
} // namespace

TEST(MatrixSmoke, IdentityStaysIdentityForAllSignatures)
{
    int m[MATRIX_N][MATRIX_N]{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };

    transpose_fixed(m);
    transpose_ptr(m);
    transpose_flat(&m[0][0], MATRIX_N);

    for (std::size_t i{0}; i < MATRIX_N; ++i)
    {
        for (std::size_t j{0}; j < MATRIX_N; ++j)
        {
            EXPECT_EQ(m[i][j], i == j ? 1 : 0) << "i=" << i << " j=" << j;
        }
    }
}

TEST(Transpose, FixedMatchesHandTransposed)
{

    int m[MATRIX_N][MATRIX_N]{};
    static_assert(sizeof m == sizeof kInput);
    std::memcpy(m, kInput, sizeof m);
    transpose_fixed(m);

    for (std::size_t i{0}; i < MATRIX_N; i++)
    {
        for (std::size_t j{0}; j < MATRIX_N; j++)
        {
            EXPECT_EQ(m[i][j], kTransposed[i][j]) << "i=" << i << " j=" << j;
        }
    }
}

TEST(Transpose, PtrMatchesHandTransposed)
{
    int m[MATRIX_N][MATRIX_N]{};
    static_assert(sizeof m == sizeof kInput);
    std::memcpy(m, kInput, sizeof m);
    transpose_ptr(m);

    for (std::size_t i{0}; i < MATRIX_N; i++)
    {
        for (std::size_t j{0}; j < MATRIX_N; j++)
        {
            EXPECT_EQ(m[i][j], kTransposed[i][j]) << "i=" << i << " j=" << j;
        }
    }
}

TEST(Transpose, FlatWorksForWidthsOneToFour)
{

    // clang-format off
    std::vector<FlatCase> cases{
        {1, {5},
            {5}},
        {2, {1, 2,
             3, 4},
            {1, 3,
             2, 4}},
        {3, {1, 2, 3,
             4, 5, 6,
             7, 8, 9},
            {1, 4, 7,
             2, 5, 8,
             3, 6, 9}},
        {4, {1,  2,  3,  4,
             5,  6,  7,  8,
             9,  10, 11, 12,
             13, 14, 15, 16},
            {1,  5,  9, 13,
             2,  6, 10, 14,
             3,  7, 11, 15,
             4,  8, 12, 16}},
    };
    // clang-format on

    for (FlatCase& c : cases)
    {
        SCOPED_TRACE(c.width);
        ASSERT_EQ(c.input.size(), c.width * c.width);
        transpose_flat(c.input.data(), c.width);
        EXPECT_EQ(c.input, c.expected);
    }
}

TEST(Transpose, TwiceRestoresOriginal)
{
    int m[MATRIX_N][MATRIX_N]{};
    static_assert(sizeof m == sizeof kInput);
    std::memcpy(m, kInput, sizeof m);
    transpose_ptr(m);
    transpose_fixed(m);

    for (std::size_t i{0}; i < MATRIX_N; i++)
    {
        for (std::size_t j{0}; j < MATRIX_N; j++)
        {
            EXPECT_EQ(m[i][j], kInput[i][j]) << "i=" << i << " j=" << j;
        }
    }
}

TEST(Transpose, FlatWidthZeroIsNoOp)
{
    int sentinal{42};
    transpose_flat(&sentinal, 0);
    EXPECT_EQ(sentinal, 42);
}

TEST(Transpose, FlatWidthZeroAcceptsNull)
{
    transpose_flat(nullptr, 0);
}

TEST(MatrixDecay, SizeofInsideFunctionIsPointerSize)
{
    int m[MATRIX_N][MATRIX_N]{};

    static_assert(sizeof(m) == MATRIX_N * MATRIX_N * sizeof(int));
    EXPECT_EQ(matrix_param_size(m), sizeof(int (*)[MATRIX_N]));

    std::cout << "sizeof m in test:     " << sizeof m << '\n'
              << "sizeof m in function: " << matrix_param_size(m) << '\n';
};