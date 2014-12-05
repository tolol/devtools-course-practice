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
    EXPECT_NEAR(conv.convert(conv.RUB, conv.EUR, 53.5948527), 1.0, 1e-5);
}

TEST_F(ConverterTest, can_Eur_To_Usd) {
    EXPECT_NEAR(conv.convert(conv.EUR, conv.USD, 1.0),
        53.5948527/42.2600685, 1e-5);
}

TEST_F(ConverterTest, can_Usd_To_Rub) {
    EXPECT_NEAR(conv.convert(conv.USD, conv.RUB, 1.0), 42.2600685, 1e-5);
}

TEST_F(ConverterTest, can_Gbp_To_Nok) {
    EXPECT_NEAR(conv.convert(conv.GBP, conv.NOK, 1.0), 70.8657/6.42, 1e-5);
}

TEST_F(ConverterTest, can_Nok_To_Jpy) {
    EXPECT_NEAR(conv.convert(conv.NOK, conv.JPY, 1.0), 6.42/0.38, 1e-5);
}

TEST_F(ConverterTest, can_Jpy_To_Gbp) {
    EXPECT_NEAR(conv.convert(conv.JPY, conv.GBP, 1.0), 0.38/70.8657, 1e-5);
}


