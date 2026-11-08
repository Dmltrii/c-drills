#include "popcount.h"

#include <gtest/gtest.h>

#include <cstdint>

namespace
{
    struct Case 
    {
        std::uint32_t input;
        int expected;
    };


    constexpr Case kCases[]
    {
        {0x00000000u, 0},
        {0x00000001u, 1},
        {0x80000000u, 1},
        {0xFFFFFFFFu, 32},
        {0xAAAAAAAAu, 16},
        {0x0F0F0F0Fu, 16},
    };

}

TEST(Popcount, AllImplementationsMatchHandCountedValues)
{
    for (const Case& c:kCases)
    {
        SCOPED_TRACE(c.input);
        EXPECT_EQ(popcount_loop(c.input), c.expected);
        EXPECT_EQ(popcount_builtin(c.input), c.expected);
        EXPECT_EQ(popcount_kernighan(c.input), c.expected);
    }
}
