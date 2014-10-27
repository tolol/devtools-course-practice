// Copyright 2014 Tolstolutskaya Olga

#include <gtest/gtest.h>

#include "include/3DVektor.h"


TEST(Vector3dTest, Can_Create) {
    Vector3d *a= new Vector3d(1, 2, 3);
    EXPECT_EQ(1, a->GetA());
    EXPECT_EQ(2, a->GetB());
    EXPECT_EQ(3, a->GetC());
}

TEST(Vector3dTest, Can_Create_Default) {
    Vector3d *a= new Vector3d();
    EXPECT_EQ(0, a->GetA());
    EXPECT_EQ(0, a->GetB());
    EXPECT_EQ(0, a->GetC());
}

TEST(Vector3dTest, Correct_Computation_Norm) {
    Vector3d *a= new Vector3d(1, 2, 3);
    EXPECT_LT(3.741657 - a->Norma(), 0.00001);
}

TEST(Vector3dTest, Correct_Computation_Normalize) {
    Vector3d *a= new Vector3d(1, 2, 3);
    a->Normalize();
    EXPECT_LT(0.267261 - a->GetA(), a->GetA());
    EXPECT_LT(0.534522 - a->GetB(), a->GetB());
    EXPECT_LT(0.801784 - a->GetC(), a->GetC());
}

TEST(Vector3dTest, Correct_Computation_ScalarProduct) {
    Vector3d *a= new Vector3d(1, 2, 3);
    Vector3d *b= new Vector3d(2, 1, -2);
    EXPECT_EQ(-2, a->ScalarProduct(b));
}

TEST(Vector3dTest, Correct_Computation_VectorProduct) {
    Vector3d *a= new Vector3d(1, 2, 3);
    Vector3d *b= new Vector3d(2, 1, -2);
    Vector3d *c= new Vector3d();
    c = a->VectorProduct(b);
    EXPECT_EQ(-7, c->GetA());
    EXPECT_EQ(8, c->GetB());
    EXPECT_EQ(-3, c->GetC());
}
