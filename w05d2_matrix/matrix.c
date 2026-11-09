#include "matrix.h"
#include <stddef.h>

void transpose_fixed(int m[][MATRIX_N])
{
    (void)m;
}
void transpose_ptr(int (*m)[MATRIX_N])
{
    (void)m;
}
void transpose_flat(int* m, size_t width)
{
    (void)m;
    (void)width;
}
