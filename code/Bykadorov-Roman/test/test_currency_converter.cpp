// Copyright 2014 Bykadorov Roman

#include <gtest/gtest.h>

#include <float.h>
#include <string>

#include "include/currencyconverter.h"

class ConverterTest : public ::testing::Test {
 protected:
    CurrencyConverter conv;
};

TEST_F(ConverterTest, can_Rub_To_Eur) {
    EXPECT_NEAR(conv.rubToEur(53.5948527), 1.0, 1e-5);
}

TEST_F(ConverterTest, can_Rub_To_Usd) {
    EXPECT_NEAR(conv.rubToUsd(42.2600685), 1.0, 1e-5);
}

TEST_F(ConverterTest, can_Usd_To_Eur) {
    EXPECT_NEAR(conv.usdToEur(1.0), 42.2600685/53.5948527, 1e-5);
}

TEST_F(ConverterTest, can_Usd_To_Rub) {
    EXPECT_NEAR(conv.usdToRub(1.0), 42.2600685, 1e-5);
}

TEST_F(ConverterTest, can_Eur_To_Rub) {
    EXPECT_NEAR(conv.eurToRub(1.0), 53.5948527, 1e-5);
}

TEST_F(ConverterTest, can_Eur_To_Usd) {
    EXPECT_NEAR(conv.eurToUsd(1.0), 53.5948527/42.2600685, 1e-5);
}

TEST_F(ConverterTest, Do_Throw_Exception_When_Value_Is_Negative) {
    EXPECT_THROW(conv.rubToEur(-100), std::string);
}

TEST_F(ConverterTest, Do_Throw_Exception_When_Value_Is_Larger_Than_DBL_MAX) {
    EXPECT_THROW(conv.eurToRub(DBL_MAX), std::string);
}

