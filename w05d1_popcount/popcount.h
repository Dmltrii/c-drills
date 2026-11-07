#ifndef POPCOUNT_H
#define POPCOUNT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int popcount_loop(uint32_t n);
int popcount_kernighan(uint32_t n);
int popcount_builtin(uint32_t n);

#ifdef __cplusplus
}
#endif

#endif /* POPCOUNT_H */
