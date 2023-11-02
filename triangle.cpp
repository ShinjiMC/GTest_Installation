#include <gtest/gtest.h>
#include <iostream>

template <typename T>
class Triangle
{
public:
    Triangle(T a, T b, T c) : sideA(a), sideB(b), sideC(c) {}
    std::string classify() const
    {
        if (sideA <= 0 || sideB <= 0 || sideC <= 0)
            return "Inválido";
        if (sideA == sideB && sideB == sideC)
            return "Equilátero";
        if (sideA == sideB || sideA == sideC || sideB == sideC)
            return "Isósceles";
        return "Escaleno";
    }
    ~Triangle() {}

private:
    T sideA, sideB, sideC;
};
namespace
{
    class TriangleTest : public ::testing::Test
    {
    protected:
        Triangle<int> *triangle;

        void SetUp() override
        {
            triangle = nullptr;
        }

        void TearDown() override
        {
            if (triangle)
            {
                delete triangle;
                triangle = nullptr;
            }
        }

        void runTestCase(int a, int b, int c, const std::string &expected)
        {
            triangle = new Triangle<int>(a, b, c);
            ASSERT_NE(nullptr, triangle);
            EXPECT_EQ(expected, triangle->classify());
        }
    };

    TEST_F(TriangleTest, EquilateralTriangle)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase(3, 3, 3, "Equilátero"));
        ASSERT_NO_FATAL_FAILURE(runTestCase(5, 5, 5, "Equilátero"));
        ASSERT_NO_FATAL_FAILURE(runTestCase(8, 8, 8, "Equilátero"));
    }

    TEST_F(TriangleTest, IsoscelesTriangle)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase(4, 3, 3, "Isósceles"));
        ASSERT_NO_FATAL_FAILURE(runTestCase(5, 5, 7, "Isósceles"));
        ASSERT_NO_FATAL_FAILURE(runTestCase(8, 12, 8, "Isósceles"));
    }

    TEST_F(TriangleTest, ScaleneTriangle)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase(3, 4, 5, "Escaleno"));
        ASSERT_NO_FATAL_FAILURE(runTestCase(5, 12, 13, "Escaleno"));
        ASSERT_NO_FATAL_FAILURE(runTestCase(7, 24, 25, "Escaleno"));
    }

    TEST_F(TriangleTest, InvalidTriangle)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase(0, 1, 2, "Inválido"));
        ASSERT_NO_FATAL_FAILURE(runTestCase(3, 0, 2, "Inválido"));
        ASSERT_NO_FATAL_FAILURE(runTestCase(3, 1, 0, "Inválido"));
        ASSERT_NO_FATAL_FAILURE(runTestCase(3, 0, 0, "Inválido"));
        ASSERT_NO_FATAL_FAILURE(runTestCase(0, 0, 0, "Inválido"));
    }
} // namespace

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}