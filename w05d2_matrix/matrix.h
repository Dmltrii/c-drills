#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

enum
{
    MATRIX_N = 4
};

#ifdef __cplusplus
extern "C"
{
#endif

    void transpose_fixed(int m[][MATRIX_N]);

    void transpose_ptr(int (*m)[MATRIX_N]);

    /* Transposes a square width x width matrix in place, stored row by row.
     * m must point to at least width * width elements.
     * When width == 0 the function does nothing and m may be NULL. */
    void transpose_flat(int* m, size_t width);

    /* Returns sizeof of its parameter. Exists only to demonstrate
     * array-to-pointer decay in tests: the result is the size of a pointer,
     * not of the matrix. */
    size_t matrix_param_size(int (*m)[MATRIX_N]);

#ifdef __cplusplus
}
#endif

#endif