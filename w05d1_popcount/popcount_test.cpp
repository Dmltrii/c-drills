#include "popcount.h"

#include <gtest/gtest.h>

TEST(PopcountSmoke, ZeroHasNoBits) {
    EXPECT_EQ(popcount_loop(0u), 0);
}