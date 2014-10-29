// Copyright 2014 Sirotin Nikita

#include <gtest/gtest.h>
#include <float.h>
#include <math.h>
#include <string>

#include "include/volumefigures.h"

class VolumeTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    Volume vol;
};

TEST_F(VolumeTest, Cube) {
    EXPECT_EQ(8.0, vol.Cube(2.0));
}

TEST_F(VolumeTest, Do_Throw_Exception_When_Volume_Is_Larger_Than_DBL_MAX_Cube) {
    EXPECT_THROW(vol.Cube(DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Larger_Than_Minus_DBL_MAX_Cube) {
    EXPECT_THROW(vol.Cube(-DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Zero_Cube) {
    EXPECT_THROW(vol.Cube(0), std::string);
}

TEST_F(VolumeTest, Sphere) {
    EXPECT_EQ(M_PI * 4 / 3, vol.Sphere(1.));
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Larger_Than_DBL_MAX_Sphere) {
    EXPECT_THROW(vol.Sphere(DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Larger_Than_Minus_DBL_MAX_Sphere) {
    EXPECT_THROW(vol.Sphere(-DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Zero_Sphere) {
    EXPECT_THROW(vol.Sphere(0), std::string);
}

TEST_F(VolumeTest, Pyramid) {
    EXPECT_EQ(4., vol.Pyramid(3., 4.));
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Larger_Than_DBL_MAX_Pyramid) {
    EXPECT_THROW(vol.Pyramid(DBL_MAX, DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Larger_Than_Minus_DBL_MAX_Pyramid) {
    EXPECT_THROW(vol.Pyramid(-DBL_MAX, -DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Zero_Pyramid) {
    EXPECT_THROW(vol.Pyramid(0, 23), std::string);
}

TEST_F(VolumeTest, Cylinder) {
    EXPECT_EQ(3. * M_PI, vol.Cylinder(3., 1.));
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Larger_Than_DBL_MAX_Cylinder) {
    EXPECT_THROW(vol.Cylinder(DBL_MAX, DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Larger_Than_Minus_DBL_MAX_Cylinder) {
    EXPECT_THROW(vol.Cylinder(-DBL_MAX, -DBL_MAX), std::string);
}

TEST_F(VolumeTest,
Do_Throw_Exception_When_Volume_Is_Zero_Cylinder) {
    EXPECT_THROW(vol.Cylinder(0, 23), std::string);
}
