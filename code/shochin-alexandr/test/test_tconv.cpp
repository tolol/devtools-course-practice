// Copyright 2014 Shochin Alexandr

#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "include/tconv.h"

class TConvTest : public ::testing::Test {
 protected:
};

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong_1) {
    TemperatureConverter tc(-300.0);
    EXPECT_THROW(tc.Convert(1) , std::string);
}

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong_2) {
    TemperatureConverter tc(-300.0);
    EXPECT_THROW(tc.Convert(2) , std::string);
}

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong_3) {
    TemperatureConverter tc(-300.0);
    EXPECT_THROW(tc.Convert(3) , std::string);
}

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_unit_Is_Wrong_3) {
    TemperatureConverter tc2(100.0);
    EXPECT_THROW(tc2.Convert(0) , std::string);
}

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_unit_Is_Wrong_4) {
    TemperatureConverter tc(-300.0);
    EXPECT_THROW(tc.Convert(4) , std::string);
}

TEST_F(TConvTest, Check_the_value_of_Kelvin) {
    TemperatureConverter tc3(200.0);
    EXPECT_EQ(tc3.Convert(1) , 473.14999999999998);
}

TEST_F(TConvTest, Check_the_value_of_Fahrenheit) {
    TemperatureConverter tc3(200.0);
    EXPECT_EQ(tc3.Convert(2) , 392.00000000000000);
}

TEST_F(TConvTest, Check_the_value_of_Newton) {
    TemperatureConverter tc3(200.0);
    EXPECT_EQ(tc3.Convert(3) , 66.000000000000000);
}
