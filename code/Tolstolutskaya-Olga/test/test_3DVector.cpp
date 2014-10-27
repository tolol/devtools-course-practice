// Copyright 2014 Tolstolutskaya Olga

#include <gtest/gtest.h>

#include "include/3DVektor.h"


TEST_F(3DVektorTest, Can_Create) {
    3DVektor a(3, 4, 5);
    EXPECT_EQ(3, a.GetA());
    EXPECT_EQ(4, a.GetB());
    EXPECT_EQ(5, a.GetC());
}

TEST_F(3DVektorTest, Can_Create_Default) {
    3DVektor a();
    EXPECT_EQ(0, a.GetA());
    EXPECT_EQ(0, a.GetB());
    EXPECT_EQ(0, a.GetC());
}

TEST_F(3DVektorTest, Correct_Computation_Norm) {
    3DVektor a(1, 2, 3);  
    EXPECT_EQ(3.741657, a.Norma());
}

TEST_F(3DVektorTest, Correct_Computation_Normalize) {
    3DVektor a(1, 2, 3);
    a.Normalize();
    EXPECT_EQ(0.267261, a.GetA());
    EXPECT_EQ(0.534522, a.GetB());
    EXPECT_EQ(0.801784, a.GetC());
}

TEST_F(3DVektorTest, Correct_Computation_ScalarProduct) {
    3DVektor a(1, 2, 3);
    3DVektor b(2, 1, -2);
    EXPECT_EQ(-2, a->ScalarProduct(b));
}

TEST_F(3DVektorTest, Correct_Computation_VectorProduct) {
    3DVektor a(1, 2, 3);
    3DVektor b(2, 1, -2);
    3DVektor c(2, 1, -2);
    c = a->VectorProduct(b);
    EXPECT_EQ(-7, c.GetA());
    EXPECT_EQ(8, c.GetB());
    EXPECT_EQ(-3, c.GetC());
}
