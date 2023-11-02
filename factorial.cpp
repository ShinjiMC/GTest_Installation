#include <gtest/gtest.h>
#include "iostream"

int factorial(int n)
{
    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return 1;
    int result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

namespace
{
    class FactorialTest : public testing::Test
    {
    protected:
    };

    TEST_F(FactorialTest, HandlesZeroInput)
    {
        EXPECT_EQ(factorial(0), 1);
    }
    TEST_F(FactorialTest, HandlesPositiveInput)
    {
        EXPECT_EQ(factorial(1), 1);
        EXPECT_EQ(factorial(2), 2);
        EXPECT_EQ(factorial(3), 6);
        EXPECT_EQ(factorial(4), 24);
        EXPECT_EQ(factorial(5), 120);
        EXPECT_EQ(factorial(8), 40320);
    }

    TEST_F(FactorialTest, HandlesNegativeInput)
    {
        EXPECT_EQ(factorial(-1), -1);
        EXPECT_EQ(factorial(-5), -1);
    }

} // namespace

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
