// Copyright 2014 Anatoliy Rozanov

#include <gtest/gtest.h>
#include <string>

#include "include/interpolationsearch.h"


class SearchTest : public ::testing::Test {
 protected:
    InterpolationSearch search;
    int n;
    int *mas;
    void creat_mas(int n_) {
        int q = 2;
        n = n_;
        mas = new int[n];
        mas[0] = q;
        for (int i = 1; i < n; i++) {
            mas[i] = mas[i - 1] + q;
        }
    }
};

TEST_F(SearchTest, Can_Search_In_Left_Half) {
    // Arrange
    n = 20;
    creat_mas(n);
    int k = 4;
    // Act
    int t = search.run(mas, n, k);
    // Assert
    EXPECT_EQ(1, t);
}
TEST_F(SearchTest, Can_Search_In_Right_Half) {
    // Arrange
    n = 20;
    creat_mas(n);
    int k = 24;
    // Act
    int t = search.run(mas, n, k);
    // Assert
    EXPECT_EQ(11, t);
}
TEST_F(SearchTest, Can_Search_In_Mid) {
    // Arrange
    n = 20;
    creat_mas(n);
    int k = 22;
    // Act
    int t = search.run(mas, n, k);
    // Assert
    EXPECT_EQ(10, t);
}
TEST_F(SearchTest, Can_Search_When_Key_Not_Found) {
    // Arrange
    n = 20;
    creat_mas(n);
    int k = 1;
    // Act
    int t = search.run(mas, n, k);
    // Assert
    EXPECT_EQ(-1, t);
}
TEST_F(SearchTest, Can_Search_When_Left_Will_Be_Key) {
    // Arrange
    n = 10;
    mas = new int[n];
    for (int i = 0; i < n - 1; i++)
        mas[i] = i + 1;
    mas[n - 1] = 12;
    int k = 3;
    // Act
    int t = search.run(mas, n, k);
    // Assert
    EXPECT_EQ(2, t);
}
TEST_F(SearchTest, Can_Search_When_Right_Will_Be_Key) {
    // Arrange
    n = 10;
    mas = new int[n];
    for (int i = 1; i < n; i++)
        mas[i] = i + 6;
    mas[0] = 4;
    int k = 8;
    // Act
    int t = search.run(mas, n, k);
    // Assert
    EXPECT_EQ(2, t);
}
TEST_F(SearchTest, Can_Search_When_Key_Less_Mas_Min) {
    // Arrange
    n = 20;
    creat_mas(n);
    int k = -10;
    // Act
    int t = search.run(mas, n, k);
    // Assert
    EXPECT_EQ(-1, t);
}
TEST_F(SearchTest, Can_Search_When_Key_More_Mas_Max) {
    // Arrange
    n = 20;
    creat_mas(n);
    int k = 50;
    // Act
    int t = search.run(mas, n, k);
    // Assert
    EXPECT_EQ(-1, t);
}
TEST_F(SearchTest, Do_Throw_Exception_When_Mas_Is_Null) {
    // Arrange
    n = 5;
    mas = 0;
    int k = 50;
    // Assert
    EXPECT_THROW(search.run(mas, n, k), std::string);
}
TEST_F(SearchTest, Do_Throw_Exception_When_n_Is_Null) {
    // Arrange
    n = 0;
    mas = 0;
    int k = 50;
    // Assert
    EXPECT_THROW(search.run(mas, n, k), std::string);
}
