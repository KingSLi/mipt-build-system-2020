#include <gtest/gtest.h>

#include "A/index.h"
#include "B/lib.h"

TEST(A, len) {
    int len = sizeof(powers)/sizeof(powers[0]);
    ASSERT_EQ(len, 6);
}

TEST(B, pow1) {
    ASSERT_EQ(binpow(2, 10), 1024);
    ASSERT_EQ(binpow(2, 1), 2);
    ASSERT_EQ(binpow(2, 0), 1);
}
