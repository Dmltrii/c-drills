#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

enum { MATRIX_N = 4 };

#ifdef __cplusplus
extern "C" {
#endif

void transpose_fixed(int m[][MATRIX_N]);
void transpose_ptr(int (*m)[MATRIX_N]);
void transpose_flat(int* m, size_t width);

#ifdef __cplusplus
}
#endif

#endif