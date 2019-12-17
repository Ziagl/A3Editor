#include "pch.h"

TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

#include "../Core/RandomNumberGenerator.h"
// Test RandomNumberGenerator
TEST(RandomNumberGenerator, randomNumber)
{
    EXPECT_LT(RandomNumberGenerator::randomNumber(14, 15), 15);
}