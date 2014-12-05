// Copyright 2014 Julia Buchina

#include <gtest/gtest.h>

#include <stdint.h>
#include <limits.h>
#include <string>

#include "include/fraction.h"

class CalculatorTest : public ::testing::Test {
 protected:
    // Fraction testFraction;
};

TEST_F(CalculatorTest, Can_Create_Default_Fraction) {
    Fraction tmp;
    EXPECT_EQ(0, tmp.getNumerator());
    EXPECT_EQ(1, tmp.getDenominator());
}

TEST_F(CalculatorTest, Can_Create_Fraction) {
    Fraction tmp(2, 3);
    EXPECT_EQ(2, tmp.getNumerator());
    EXPECT_EQ(3, tmp.getDenominator());
}

TEST_F(CalculatorTest, Cannot_Create_Fraction_Divided_By_Zero) {
    EXPECT_THROW(Fraction(2, 0), std::string);
}

TEST_F(CalculatorTest, Can_Create_Fraction_By_Copying) {
    Fraction tmp1(2, 3);
    Fraction tmp2(tmp1);
    EXPECT_EQ(tmp1.getNumerator(), tmp2.getNumerator());
    EXPECT_EQ(tmp1.getDenominator(), tmp2.getDenominator());
}

TEST_F(CalculatorTest, Can_Get_Numerator) {
    Fraction tmp(2, 3);
    EXPECT_EQ(2, tmp.getNumerator());
}

TEST_F(CalculatorTest, Can_Get_Denominator) {
    Fraction tmp(2, 3);
    EXPECT_EQ(3, tmp.getDenominator());
}

TEST_F(CalculatorTest, Can_Set_Numerator) {
    Fraction tmp;
    tmp.setNumerator(2);
    EXPECT_EQ(2, tmp.getNumerator());
}

TEST_F(CalculatorTest, Can_Set_Denominator) {
    Fraction tmp;
    tmp.setDenominator(2);
    EXPECT_EQ(2, tmp.getDenominator());
}

TEST_F(CalculatorTest, Cannot_Set_Denominator_Zero) {
    Fraction tmp;
    EXPECT_THROW(tmp.setDenominator(0), std::string);
}

TEST_F(CalculatorTest, Can_Equate_Fractions) {
    Fraction tmp1(2, 3);
    Fraction tmp2;
    tmp2 = tmp1;
    EXPECT_EQ(tmp1.getNumerator(), tmp2.getNumerator());
    EXPECT_EQ(tmp1.getDenominator(), tmp2.getDenominator());
}

TEST_F(CalculatorTest, Can_Add_Fraction) {
    Fraction tmp1(1, 3);
    Fraction tmp2(1, 3);
    tmp1 = tmp1 + tmp2;
    EXPECT_EQ(2, tmp1.getNumerator());
    EXPECT_EQ(3, tmp1.getDenominator());
}

TEST_F(CalculatorTest, Cannot_Add_Fraction_Numerator_Over_MaxInt) {
    Fraction tmp1(2147483647, 1);
    Fraction tmp2(2, 1);
    EXPECT_THROW(tmp1 + tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Add_Fraction_Numerator_Under_MinInt) {
    Fraction tmp1(-2147483647, 1);
    Fraction tmp2(-2, 1);
    EXPECT_THROW(tmp1 + tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Add_Fraction_Denominator_Over_MaxInt) {
    Fraction tmp1(1, 2147483641);
    Fraction tmp2(1, 2);
    EXPECT_THROW(tmp1 + tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Add_Fraction_Denominator_Under_MinInt) {
    Fraction tmp1(1, -2147483641);
    Fraction tmp2(1, 2);
    EXPECT_THROW(tmp1 + tmp2, std::string);
}

TEST_F(CalculatorTest, Can_Sutract_Fraction) {
    Fraction tmp1(2, 3);
    Fraction tmp2(1, 3);
    tmp1 = tmp1 - tmp2;
    EXPECT_EQ(1, tmp1.getNumerator());
    EXPECT_EQ(3, tmp1.getDenominator());
}

TEST_F(CalculatorTest, Cannot_Subtract_Fraction_Numerator_Over_MaxInt) {
    Fraction tmp1(2147483647, 1);
    Fraction tmp2(-2, 1);
    EXPECT_THROW(tmp1 - tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Subtract_Fraction_Numerator_Under_MinInt) {
    Fraction tmp1(-2147483647, 1);
    Fraction tmp2(2, 1);
    EXPECT_THROW(tmp1 - tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Subtract_Fraction_Denominator_Over_MaxInt) {
    Fraction tmp1(1, 2147483641);
    Fraction tmp2(-1, 2);
    EXPECT_THROW(tmp1 - tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Subtract_Fraction_Denominator_Under_MinInt) {
    Fraction tmp1(1, -2147483647);
    Fraction tmp2(-1, 2);
    EXPECT_THROW(tmp1 - tmp2, std::string);
}

TEST_F(CalculatorTest, Can_Multiply_Fraction) {
    Fraction tmp1(1, 3);
    Fraction tmp2(1, 2);
    tmp1 = tmp1 * tmp2;
    EXPECT_EQ(1, tmp1.getNumerator());
    EXPECT_EQ(6, tmp1.getDenominator());
}

TEST_F(CalculatorTest, Cannot_Multiply_Fraction_Numerator_Over_MaxInt) {
    Fraction tmp1(2147483647, 1);
    Fraction tmp2(2, 1);
    EXPECT_THROW(tmp1 * tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Multiply_Fraction_Numerator_Under_MinInt) {
    Fraction tmp1(2147483647, 1);
    Fraction tmp2(-2, 1);
    EXPECT_THROW(tmp1 * tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Multiply_Fraction_Denominator_Over_MaxInt) {
    Fraction tmp1(1, 2147483647);
    Fraction tmp2(1, 2);
    EXPECT_THROW(tmp1 * tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Multiply_Fraction_Denominator_Under_MinInt) {
    Fraction tmp1(1, 2147483647);
    Fraction tmp2(1, -2);
    EXPECT_THROW(tmp1 * tmp2, std::string);
}

TEST_F(CalculatorTest, Can_Divide_Fraction) {
    Fraction tmp1(1, 3);
    Fraction tmp2(1, 2);
    tmp1 = tmp1 / tmp2;
    EXPECT_EQ(2, tmp1.getNumerator());
    EXPECT_EQ(3, tmp1.getDenominator());
}

TEST_F(CalculatorTest, Cannot_Divide_Fraction_Numerator_Over_MaxInt) {
    Fraction tmp1(2, 1);
    Fraction tmp2(1, 2147483647);
    EXPECT_THROW(tmp1 / tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Divide_Fraction_Numerator_Under_MinInt) {
    Fraction tmp1(-2, 1);
    Fraction tmp2(1, 2147483647);
    EXPECT_THROW(tmp1 / tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Divide_Fraction_Denominator_Over_MaxInt) {
    Fraction tmp1(1, 2);
    Fraction tmp2(2147483647, 1);
    EXPECT_THROW(tmp1 / tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Divide_Fraction_Denominator_Under_MinInt) {
    Fraction tmp1(1, -2);
    Fraction tmp2(2147483647, 1);
    EXPECT_THROW(tmp1 / tmp2, std::string);
}

TEST_F(CalculatorTest, Cannot_Divide_Fraction_Denominator_Zero) {
    Fraction tmp1(1, 2);
    Fraction tmp2(0, 2);
    EXPECT_THROW(tmp1 / tmp2, std::string);
}
