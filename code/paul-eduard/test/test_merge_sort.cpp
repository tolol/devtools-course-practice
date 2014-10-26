// Copyright 2014 Paul Eduard

#include <gtest/gtest.h>
#include <climits>
#include "include/merge-sort.h"

TEST(MergeSortTest, Null_Pointer) {
    // Arrange
    int *a = 0;
    // Act
    int ret = Merge_Sort(a, 0, 5);
    // Assert
    EXPECT_EQ(-1, ret);
}

TEST(MergeSortTest, Zero_Elements_For_Sort) {
    // Arrange
    int *a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i;
    }
    // Act
    Merge_Sort(a, 0, 0);
    // Assert
    EXPECT_EQ(0, a[0]);
    EXPECT_EQ(1, a[1]);
    EXPECT_EQ(2, a[2]);
    EXPECT_EQ(3, a[3]);
    EXPECT_EQ(4, a[4]);
    delete []a;
}
TEST(MergeSortTest, Swapped_Left_Right_Borders) {
    // Arrange
    int *a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i;
    }
    // Act
    Merge_Sort(a, 3, 1);
    // Assert
    EXPECT_EQ(0, a[0]);
    EXPECT_EQ(1, a[1]);
    EXPECT_EQ(2, a[2]);
    EXPECT_EQ(3, a[3]);
    EXPECT_EQ(4, a[4]);
    delete []a;
}
TEST(MergeSortTest, Partial_Sort) {
    // Arrange
    int *a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = 5 - i;
    }
    // Act
    Merge_Sort(a, 1, 3);
    // Assert
    EXPECT_EQ(5, a[0]);
    EXPECT_EQ(2, a[1]);
    EXPECT_EQ(3, a[2]);
    EXPECT_EQ(4, a[3]);
    EXPECT_EQ(1, a[4]);
    delete []a;
}
TEST(MergeSortTest, Full_Sort) {
    // Arrange
    const int N = 1000;
    int *a = new int[N];
    for (int i = 0; i < N; i++) {
        a[i] = N - i;
    }
    // Act
    Merge_Sort(a, 0, N-1);
    // Assert
    for (int i = 0; i < N; i++) EXPECT_EQ(i+1, a[i]);
    delete []a;
}
