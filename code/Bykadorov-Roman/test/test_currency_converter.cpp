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
    EXPECT_EQ(conv.rubToEur(53.5948527), 1);
}

TEST_F(ConverterTest, can_Rub_To_Usd) {
    EXPECT_EQ(conv.rubToUsd(42.2600685), 1);
}

TEST_F(ConverterTest, can_Usd_To_Eur) {
    EXPECT_EQ(conv.usdToEur(1), 42.2600685/53.5948527);
}

TEST_F(ConverterTest, can_Usd_To_Rub) {
    EXPECT_EQ(conv.usdToRub(1), 42.2600685);
}

TEST_F(ConverterTest, can_Eur_To_Rub) {
    EXPECT_EQ(conv.eurToRub(1), 53.5948527);
}

TEST_F(ConverterTest, can_Eur_To_Usd) {
    EXPECT_EQ(conv.eurToUsd(1), 53.5948527/42.2600685);
}

TEST_F(ConverterTest, Do_Throw_Exception_When_Value_Is_Negative) {
    EXPECT_THROW(conv.rubToEur(-100), std::string);
}

TEST_F(ConverterTest, Do_Throw_Exception_When_Value_Is_Larger_Than_DBL_MAX) {
    EXPECT_THROW(conv.eurToRub(DBL_MAX), std::string);
}

