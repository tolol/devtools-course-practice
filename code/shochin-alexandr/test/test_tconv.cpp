// Copyright 2014 Shochin Alexandr

#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "include/tconv.h"

class TempConvTest : public ::testing::Test {
 protected:
    TemperatureConvertor tempconv;
};

TEST_F(TempConvTest, Throw_Exception_When_Value_For_Celsius_Is_Wrong) {
    Temperature temp;
    temp.value = -300;
    temp.unit = Celsius;
    EXPECT_THROW(tempconv.Convert(temp, Newton), std::string);
}
TEST_F(TempConvTest, Throw_Exception_When_Value_For_Kelvin_Is_Wrong) {
    Temperature temp;
    temp.value = -3;
    temp.unit = Kelvin;
    EXPECT_THROW(tempconv.Convert(temp, Newton), std::string);
}
TEST_F(TempConvTest, Throw_Exception_When_Value_For_Newton_Is_Wrong) {
    Temperature temp;
    temp.value = -100;
    temp.unit = Newton;
    EXPECT_THROW(tempconv.Convert(temp, Kelvin), std::string);
}
TEST_F(TempConvTest, Throw_Exception_When_Value_For_Fahrenheit_Is_Wrong) {
    Temperature temp;
    temp.value = -500;
    temp.unit = Fahrenheit;
    EXPECT_THROW(tempconv.Convert(temp, Newton), std::string);
}

TEST_F(TempConvTest, Convert_Celsius_To_Kelvin) {
    Temperature temp;
    temp.value = 50;
    temp.unit = Celsius;
    double var = 323.14999999999998;
    EXPECT_NEAR(var, tempconv.Convert(temp, Kelvin), 1e-5);
}

TEST_F(TempConvTest, Convert_Celsius_To_Fahrenheit) {
    Temperature temp;
    temp.value = 50;
    temp.unit = Celsius;
    double var = 121.99999999999999;
    EXPECT_NEAR(var, tempconv.Convert(temp, Fahrenheit), 1e-5);
}

TEST_F(TempConvTest, Convert_Celsius_To_Newton) {
    Temperature temp;
    temp.value = 50;
    temp.unit = Celsius;
    double var = 16.500000000000000;
    EXPECT_NEAR(var, tempconv.Convert(temp, Newton), 1e-5);
}

TEST_F(TempConvTest, Convert_Kelvin_To_Celsius) {
    Temperature temp;
    temp.value = 50;
    temp.unit = Kelvin;
    double var = -223.14999999999998;
    EXPECT_NEAR(var, tempconv.Convert(temp, Celsius), 1e-5);
}

TEST_F(TempConvTest, Convert_Fahrenheit_To_Celsius) {
    Temperature temp;
    temp.value = 50;
    temp.unit = Fahrenheit;
    double var = 10.000000000000000;
    EXPECT_NEAR(var, tempconv.Convert(temp, Celsius), 1e-5);
}

TEST_F(TempConvTest, Convert_Newton_To_Celsius) {
    Temperature temp;
    temp.value = 50;
    temp.unit = Newton;
    double var = 151.51515151515150;
    EXPECT_NEAR(var, tempconv.Convert(temp, Celsius), 1e-5);
}
