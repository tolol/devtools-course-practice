// Copyright 2014 Alexey Kokoshnikov

#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "include/simplecalculator.h"

class CalculatorTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    SimpleCalculator calc;
};

TEST_F(CalculatorTest, BinToHex) {
    EXPECT_EQ("27", calc.BinToHex(100111));
}

TEST_F(CalculatorTest, BinToHex_Sign) {
    EXPECT_EQ("-27", calc.BinToHex(-100111));
}

TEST_F(CalculatorTest, HexToBin) {
    EXPECT_EQ(11111, calc.HexToBin("1f"));
}

TEST_F(CalculatorTest, HexToBin_Sign) {
    EXPECT_EQ(-11111, calc.HexToBin("-1f"));
}

TEST_F(CalculatorTest, BinToOct) {
    EXPECT_EQ(10, calc.BinToOct(1000));
}

TEST_F(CalculatorTest, BinToOct_Sign) {
    EXPECT_EQ(-10, calc.BinToOct(-1000));
}

TEST_F(CalculatorTest, OctToBin) {
    EXPECT_EQ(1010, calc.OctToBin(12));
}

TEST_F(CalculatorTest, OctToBin_Sign) {
    EXPECT_EQ(-1010, calc.OctToBin(-12));
}

TEST_F(CalculatorTest, OctToDec_Stress_1) {
    EXPECT_EQ(0, calc.OctToBin(79));
}

TEST_F(CalculatorTest, OctToDec_Stress_2) {
    EXPECT_EQ(0, calc.OctToBin(9));
}

TEST_F(CalculatorTest, BinToDec_Stress_1) {
    EXPECT_EQ(0, calc.BinToOct(33));
}

TEST_F(CalculatorTest, BinToDec_Stress_2) {
    EXPECT_EQ(0, calc.OctToBin(9));
}
/*TEST_F(CalculatorTest, Do_Throw_Exception_When_Sum_Is_Larger_Than_INT_MAX) {
    EXPECT_THROW(calc.Add(INT_MAX, INT_MAX), std::string);
}
*/
