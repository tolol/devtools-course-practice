// Copyright 2014 Gladilov Gleb

#include <gtest/gtest.h>

#include <string>

#include "include/complexcalculator.h"

class ComplexTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(ComplexTest, Can_Create_With_Real_And_Imaginary) {
    // Arrange & Act
    Complex test(26, 26);

    // Assert
    EXPECT_EQ(26, test.GetReal());
    EXPECT_EQ(26, test.GetImaginary());
}
TEST_F(ComplexTest, Can_Create_Via_Copying) {
    // Arrange
    Complex test(26, 26);

    // Act
    Complex tested = test;

    // Assert
    EXPECT_EQ(26, tested.GetReal());
    EXPECT_EQ(26, tested.GetImaginary());
}
TEST_F(ComplexTest, Can_Set_Real) {
    // Arrange
    Complex test;

    // Act
    test.SetReal(26);

    // Assert
    EXPECT_EQ(26, test.GetReal());
}

TEST_F(ComplexTest, Can_Set_Imaginary) {
    // Arrange
    Complex test;

    // Act
    test.SetImaginary(26);

    // Assert
    EXPECT_EQ(26, test.GetImaginary());
}
TEST_F(ComplexTest, Can_Add_Complex) {
    // Arrange
    Complex test(26, 26);
    Complex tested(1, 1);

    // Act
    tested.Add(test);

    // Assert
    EXPECT_EQ(27, tested.GetReal());
    EXPECT_EQ(27, tested.GetImaginary());
}

TEST_F(ComplexTest, Can_Difference_Complex) {
    // Arrange
    Complex test(26, 26);
    Complex tested(1, 1);

    // Act
    tested.Difference(test);

    // Assert
    EXPECT_EQ(-25, tested.GetReal());
    EXPECT_EQ(-25, tested.GetImaginary());
}

TEST_F(ComplexTest, Can_Multiplication_Complex) {
    // Arrange
    Complex test(5, 3);
    Complex tested(4, 6);

    // Act
    tested.Multiplication(test);

    // Assert
    EXPECT_EQ(2, tested.GetReal());
    EXPECT_EQ(42, tested.GetImaginary());
}
TEST_F(ComplexTest, Can_Division_Complex) {
    // Arrange
    Complex test(15, 15);
    Complex tested(27, 30);

    // Act
    tested.Division(test);

    // Assert
    EXPECT_NEAR(1.9, tested.GetReal(), ComplexTest::epsilon);
    EXPECT_NEAR(0.1, tested.GetImaginary(), ComplexTest::epsilon);
}
TEST_F(ComplexTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    Complex test;
    Complex tested(26, 26);

    // Act & Assert
    EXPECT_THROW(tested.Division(test), std::string);
}
