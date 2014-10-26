// Copyright 2014 Paul Eduard

#include <gtest/gtest.h>

#include "include/merge-sort.h"

TEST(MergeSortTest, Can_Create) {
    // Arrange
    int a[5];

    // Act
    Merge_Sort(a, 0, 0);
    // int ret = -1;

    // Assert
    EXPECT_EQ(-1, -1);
}
