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

TEST_F(CalculatorTest, HexToBin_negativ) {
    EXPECT_EQ(0, calc.HexToBin("g"));
}

TEST_F(CalculatorTest, BinToHex_negativ) {
    EXPECT_EQ("", calc.BinToHex(12000));
}

TEST_F(CalculatorTest, BinToHex_0) {
    EXPECT_EQ("10", calc.BinToHex(10000));
}

TEST_F(CalculatorTest, BinToHex_123) {
    EXPECT_EQ("123", calc.BinToHex(100100011));
}

TEST_F(CalculatorTest, BinToHex_45) {
    EXPECT_EQ("45", calc.BinToHex(1000101));
}

TEST_F(CalculatorTest, BinToHex_67) {
    EXPECT_EQ("67", calc.BinToHex(1100111));
}

TEST_F(CalculatorTest, BinToHex_89) {
    EXPECT_EQ("89", calc.BinToHex(10001001));
}

TEST_F(CalculatorTest, BinToHex_ab) {
    EXPECT_EQ("ab", calc.BinToHex(10101011));
}

TEST_F(CalculatorTest, BinToHex_cd) {
    EXPECT_EQ("cd", calc.BinToHex(11001101));
}

TEST_F(CalculatorTest, BinToHex_ef) {
    EXPECT_EQ("ef", calc.BinToHex(11101111));
}

TEST_F(CalculatorTest, HexToBin_0) {
    EXPECT_EQ(10000, calc.HexToBin("10"));
}

TEST_F(CalculatorTest, HexToBin_123) {
    EXPECT_EQ(100100011, calc.HexToBin("123"));
}

TEST_F(CalculatorTest, HexToBin_45) {
    EXPECT_EQ(1000101, calc.HexToBin("45"));
}

TEST_F(CalculatorTest, HexToBin_67) {
    EXPECT_EQ(1100111, calc.HexToBin("67"));
}

TEST_F(CalculatorTest, HexToBin_89) {
    EXPECT_EQ(10001001, calc.HexToBin("89"));
}

TEST_F(CalculatorTest, HexToBin_ab) {
    EXPECT_EQ(10101011, calc.HexToBin("ab"));
}

TEST_F(CalculatorTest, HexToBin_cd) {
    EXPECT_EQ(11001101, calc.HexToBin("cd"));
}

TEST_F(CalculatorTest, HexToBin_ef) {
    EXPECT_EQ(11101111, calc.HexToBin("ef"));
}

TEST_F(CalculatorTest, BinToHex_Sign) {
    EXPECT_EQ("-27", calc.BinToHex(-100111));
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
