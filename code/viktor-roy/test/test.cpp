// Copyright 2014 Roy Viktor

#include <gtest/gtest.h>
#include <../include/mat_stat.hpp>

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
TEST(VarianceValueTest, Can_Calculate_Variance_Value) {
    // arrange
    mat_stat mat;
    double probability[4] = {0.4, 0.1, 0.2, 0.3};
    double statisticValues[4] = {0.0, 1.0, 2.0, 3.0};
    // act
    double value = mat.variance(statisticValues, probability, 4);
    // assert
    EXPECT_EQ(value, 1.64);
}
TEST(VarianceValueTest, Can_Calculate_Another_Variance_Value) {
    // arrange
    mat_stat mat;
    double probability[6] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.0};
    double statisticValues[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    // act
    double value = mat.variance(statisticValues, probability, 6);
    // assert
    EXPECT_EQ(value, 1);
}

TEST(CreationTest, EmptyTest) {
  mat_stat mat;
}
TEST(GarbageTest, CanDropExceptionStatisticValue) {
    // arrange
    mat_stat mat;
    double probability[6] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.0};
    double * statisticValues = 0;
    int count = 6;
    // act
    double value = mat.expectedValue(statisticValues, probability, count);
    // assert
    EXPECT_EQ(value, 0);
}
TEST(GarbageTest, CanDropExceptionProbability) {
    // arrange
    mat_stat mat;
    double * probability = 0;
    double statisticValues[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    int count = 6;
    // act
    double value = mat.expectedValue(statisticValues, probability, count);
    // assert
    EXPECT_EQ(value, 0);
}
TEST(GarbageTest, CanDropExceptionCount) {
    // arrange
    mat_stat mat;
    double probability[6] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.0};
    double statisticValues[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    int count = 0;
    // act
    double value = mat.expectedValue(statisticValues, probability, count);
    // assert
    EXPECT_EQ(value, 0);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
