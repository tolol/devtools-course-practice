// Copyright 2014 Shochin Alexandr

#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "include/tconv.h"

class TemperatureConverterTest : public ::testing::Test {
 protected:
    TemperatureConverter tc(-300);
    TemperatureConverter tc2(100);
    TemperatureConverter tc3(200);
};

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong) {
    EXPECT_THROW(tc.Convert(1) , std::string);
}

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong) {
    EXPECT_THROW(tc.Convert(2) , std::string);
}

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong) {
    EXPECT_THROW(tc.Convert(3) , std::string);
}

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong) {
    EXPECT_THROW(tc2.Convert(0) , std::string);
}

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong) {
    EXPECT_THROW(tc2.Convert(0) , std::string);
}

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_Celsius_Is_Wrong) {
    EXPECT_THROW(tc2.Convert(0) , std::string);
}

TEST_F(TConvTest, Do_Throw_Exception_When_Value_For_unit_Is_Wrong) {
    EXPECT_THROW(tc.Convert(4) , std::string);
}

TEST_F(TConvTest, Check_the_value_of_Kelvin) {
    EXPECT_THROW(tc3.Convert(1) , 473.14999999999998);
}

TEST_F(TConvTest, Check_the_value_of_Fahrenheit) {
    EXPECT_THROW(tc3.Convert(2) , 392.00000000000000);
}

TEST_F(TConvTest, Check_the_value_of_Newton) {
    EXPECT_THROW(tc3.Convert(3) , 66.000000000000000);
}
