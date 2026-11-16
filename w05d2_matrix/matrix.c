#include "matrix.h"
#include <assert.h>
#include <stddef.h>

void transpose_fixed(int m[][MATRIX_N])
{
    for (size_t i = 0; i < MATRIX_N; i++)
    {
        for (size_t j = i + 1; j < MATRIX_N; j++)
        {
            int tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }
}

void transpose_ptr(int (*m)[MATRIX_N])
{
    for (size_t i = 0; i < MATRIX_N; i++)
    {
        for (size_t j = i + 1; j < MATRIX_N; j++)
        {
            int tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }
}

void transpose_flat(int* m, size_t width)
{
    assert(m != NULL || width == 0);
    for (size_t i = 0; i < width; i++)
    {
        for (size_t j = i + 1; j < width; j++)
        {
            int tmp = m[i * width + j];
            m[i * width + j] = m[j * width + i];
            m[j * width + i] = tmp;
        }
    }
}

size_t matrix_param_size(int (*m)[MATRIX_N])
{
    return sizeof m;
}
