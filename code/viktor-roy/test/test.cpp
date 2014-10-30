// Copyright 2014 Roy Viktor

#include <gtest/gtest.h>
#include <../include/mat_stat.hpp>

TEST(MathTest, TwoPlusTwoEqualsFour) {
    EXPECT_EQ(2 + 2, 4);
}
TEST(ExpextedValueTest, Can_Calculate_Expected_Value) {
    // arrange
    mat_stat mat;
    double probability[4] = {0.4, 0.1, 0.2, 0.3};
    double statisticValues[4] = {0.0, 1.0, 2.0, 3.0};
    // act
    double value = mat.expectedValue(statisticValues, probability, 4);
    // assert
    EXPECT_EQ(value, 1.4);
}
TEST(ExpextedValueTest, Can_Calculate_Another_Expected_Value) {
    // arrange
    mat_stat mat;
    double probability[6] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.0};
    double statisticValues[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    // act
    double value = mat.expectedValue(statisticValues, probability, 6);
    // assert
    EXPECT_EQ(value, 3);
}
TEST(ExpextedValueTest, Can_Calculate_Variance_Value) {
    // arrange
    mat_stat mat;
    double probability[4] = {0.4, 0.1, 0.2, 0.3};
    double statisticValues[4] = {0.0, 1.0, 2.0, 3.0};
    // act
    double value = mat.variance(statisticValues, probability, 4);
    // assert
    EXPECT_EQ(value, 1.64);
}
TEST(ExpextedValueTest, Can_Calculate_Another_Variance_Value) {
    // arrange
    mat_stat mat;
    double probability[6] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.0};
    double statisticValues[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    // act
    double value = mat.variance(statisticValues, probability, 6);
    // assert
    EXPECT_EQ(value, 1);
}
TEST(SetGetValueTest, Can_Set_Get_Values) {
    // arrange
    mat_stat mat;
    int n = 6;
    int getN;
    double probability[6] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.0};
    double statisticValues[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    double getProbability[6];
    double getStatisticValues[6];
    // act
    mat.setValues(statisticValues, probability, n);
    mat.getValues(getStatisticValues, getProbability, getN);
    // assert
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(statisticValues[i], getStatisticValues[i]);
        EXPECT_EQ(probability[i], getProbability[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
