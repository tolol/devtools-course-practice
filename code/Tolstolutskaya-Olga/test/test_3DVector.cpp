// Copyright 2014 Tolstolutskaya Olga

#include <gtest/gtest.h>

#include "include/3DVector.h"

#define EPSILON 1e-5

TEST(Vector3dTest, Can_Create) {
    Vector3d a(1, 2, 3);
    EXPECT_EQ(1, a.GetA());
    EXPECT_EQ(2, a.GetB());
    EXPECT_EQ(3, a.GetC());
}

TEST(Vector3dTest, Can_Create_Default) {
    Vector3d a();
    EXPECT_EQ(0, a.GetA());
    EXPECT_EQ(0, a.GetB());
    EXPECT_EQ(0, a.GetC());
}

TEST(Vector3dTest, Correct_Computation_Norm) {
    Vector3d a(1, 2, 3);
    EXPECT_NEAR(3.741657, a.Norm(), 1e-5);
}

TEST(Vector3dTest, Correct_Computation_Normalize) {
    Vector3d a(1, 2, 3);
    a.Normalize();
    EXPECT_NEAR(0.267261, a.GetA(), 1e-5);
    EXPECT_NEAR(0.534522, a.GetB(), 1e-5);
    EXPECT_NEAR(0.801784, a.GetC(), 1e-5);
}

TEST(Vector3dTest, Correct_Computation_Normalize2) {
    Vector3d a(-1, -2, -3);
    a.Normalize();
    EXPECT_NEAR(-0.267261, a.GetA(), 1e-5);
    EXPECT_NEAR(-0.534522, a.GetB(), 1e-5);
    EXPECT_NEAR(-0.801784, a.GetC(), 1e-5);
}

TEST(Vector3dTest, Correct_Computation_Normalize_Null) {
    Vector3d a();
    a.Normalize();
}

TEST(Vector3dTest, Correct_Computation_ScalarProduct) {
    Vector3d a(1, 2, 3);
    Vector3d b(2, 1, -2);
    EXPECT_EQ(-2, a.ScalarProduct(b));
}

TEST(Vector3dTest, Correct_Computation_VectorProduct) {
    Vector3d a(1, 2, 3);
    Vector3d b(2, 1, -2);
    Vector3d c();
    c = a.VectorProduct(b);
    EXPECT_EQ(-7, c.GetA());
    EXPECT_EQ(8, c.GetB());
    EXPECT_EQ(-3, c.GetC());
}

TEST(Vector3dTest, Correct_Computation_Normalize2) {
    Vector3d a(1, 1, 0);
    a.Normalize();
    EXPECT_NEAR(0.707107, a.GetA(), 1e-5);
    EXPECT_NEAR(0.707107, a.GetB(), 1e-5);
    EXPECT_NEAR(0.0, a.GetC(), 1e-5);
}
