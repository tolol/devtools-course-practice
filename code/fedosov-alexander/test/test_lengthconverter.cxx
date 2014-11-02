// Copyright 2014 Fedosov Alexander
#include <gtest/gtest.h>
#include <float.h>
#include <cstdlib>
#include "include/lengthconverter.hpp"

class lengthconverterTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}
};

TEST_F(lengthconverterTest, conversion_test1) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertMetersToInches(100.0), 3937.01, 0.001);
}
TEST_F(lengthconverterTest, conversion_test2) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertMetersToFoots(100.0), 328.08, 0.001);
}
TEST_F(lengthconverterTest, conversion_test3) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertMetersToYards(100.0), 109.36, 0.001);
}
TEST_F(lengthconverterTest, conversion_test4) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertMetersToMiles(100.0), 0.06214, 0.0001);
}

TEST_F(lengthconverterTest, conversion_test5) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertInchesToMeters(100.0), 2.54, 0.001);
}
TEST_F(lengthconverterTest, conversion_test6) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertInchesToFoots(100.0), 8.33, 0.001);
}
TEST_F(lengthconverterTest, conversion_test7) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertInchesToYards(100.0), 2.78, 0.001);
}
TEST_F(lengthconverterTest, conversion_test8) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertInchesToMiles(100.0), 0.0016, 0.00001);
}

TEST_F(lengthconverterTest, conversion_test9) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertFootsToMeters(100.0), 30.48, 0.001);
}
TEST_F(lengthconverterTest, conversion_test10) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertFootsToInches(100.0), 1200.0, 0.001);
}
TEST_F(lengthconverterTest, conversion_test11) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertFootsToYards(100.0), 33.3333, 0.0001);
}
TEST_F(lengthconverterTest, conversion_test12) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertFootsToMiles(100.0), 0.019, 0.0001);
}

TEST_F(lengthconverterTest, conversion_test13) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertYardsToMeters(100.0), 91.44, 0.001);
}
TEST_F(lengthconverterTest, conversion_test14) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertYardsToInches(100.0), 3600.00, 0.001);
}
TEST_F(lengthconverterTest, conversion_test15) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertYardsToFoots(100.0), 300.0, 0.001);
}
TEST_F(lengthconverterTest, conversion_test16) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertYardsToMiles(100.0), 0.05682, 0.0001);
}

TEST_F(lengthconverterTest, conversion_test17) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertMilesToMeters(100.0), 160934.4, 0.001);
}
TEST_F(lengthconverterTest, conversion_test18) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertMilesToInches(100.0), 6336000.0, 0.001);
}
TEST_F(lengthconverterTest, conversion_test19) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertMilesToFoots(100.0), 528000.0, 0.001);
}
TEST_F(lengthconverterTest, conversion_test20) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertMilesToYards(100.0), 176000.0, 0.001);
}

TEST_F(lengthconverterTest, conversion_test21) {
    LengthConverter converter = LengthConverter();
    EXPECT_NEAR(converter.convertMilesToYards(-100.0), 0.0, 0.001);
}
