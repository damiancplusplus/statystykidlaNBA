#include "main.cpp"
#include <gtest gtest.h="">

// Test enum
TEST(FactorialTest, TestEnum) {
  EXPECT_EQ(1, Factorial(Blok));
  EXPECT_EQ(2, Factorial(za2));
  EXPECT_EQ(3, Factorial(za3));
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
</gtest>