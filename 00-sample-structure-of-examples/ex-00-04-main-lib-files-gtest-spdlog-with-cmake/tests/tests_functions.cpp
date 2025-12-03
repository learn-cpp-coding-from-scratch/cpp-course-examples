#include <gtest/gtest.h>

#include "functions.hpp"

// Tests for add ---
TEST(FunctionsTest, TestAdd)
{
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(-2, -3), -5);
}
