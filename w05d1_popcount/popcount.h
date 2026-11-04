#ifndef POPCOUNT_H
#define POPCOUNT_H

#include <cstdint>

int popcount_loop(std::uint32_t n);
int popcount_kernighan(std::uint32_t n);
int popcount_std(std::uint32_t n);

#endif