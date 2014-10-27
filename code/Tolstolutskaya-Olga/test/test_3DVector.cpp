// Copyright 2014 Tolstolutskaya Olga

#include <gtest/gtest.h>

#include "include/Vector3d.h"


TEST(Vector3dTest, Can_Create) {
    Vector3d a(3, 4, 5);
    EXPECT_EQ(3, a.GetA());
    EXPECT_EQ(4, a.GetB());
    EXPECT_EQ(5, a.GetC());
}

TEST(Vector3dTest, Can_Create_Default) {
    Vector3d a();
    EXPECT_EQ(0, a.GetA());
    EXPECT_EQ(0, a.GetB());
    EXPECT_EQ(0, a.GetC());
}

TEST(Vector3dTest, Correct_Computation_Norm) {
    Vector3d a(1, 2, 3);
    EXPECT_EQ(3.741657, a.Norma());
}

TEST(Vector3dTest, Correct_Computation_Normalize) {
    Vector3d a(1, 2, 3);
    a.Normalize();
    EXPECT_EQ(0.267261, a.GetA());
    EXPECT_EQ(0.534522, a.GetB());
    EXPECT_EQ(0.801784, a.GetC());
}

TEST(Vector3dTest, Correct_Computation_ScalarProduct) {
    Vector3d a(1, 2, 3);
    Vector3d b(2, 1, -2);
    EXPECT_EQ(-2, a->ScalarProduct(b));
}

TEST(Vector3dTest, Correct_Computation_VectorProduct) {
    Vector3d a(1, 2, 3);
    Vector3d b(2, 1, -2);
    Vector3d c(2, 1, -2);
    c = a->VectorProduct(b);
    EXPECT_EQ(-7, c.GetA());
    EXPECT_EQ(8, c.GetB());
    EXPECT_EQ(-3, c.GetC());
}
