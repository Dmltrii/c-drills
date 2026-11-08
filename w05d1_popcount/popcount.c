#include "popcount.h"

int popcount_loop(uint32_t n)
{
    int count=0;
    while(n)
    {
        count += (int) (n & 1u); 
        n = n >> 1;
    }
    return count; 
}

int popcount_kernighan(uint32_t n)
{
    int count=0;
    while(n)
    {
        count++;
        n&=n-1;
    }
    return count;
}

int popcount_builtin(uint32_t n)
{
    return __builtin_popcount(n);
}
