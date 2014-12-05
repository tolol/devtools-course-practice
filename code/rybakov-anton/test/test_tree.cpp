// Copyright 2014 Anton Rybakov

#include <gtest/gtest.h>

#include <string>
#include "include/tree.h"

// Basic tests

TEST(TreeTest, Creating) {
    // Arrange
    _tree<int> test_tree;
    // Act
    test_tree.add(0);
    // Assert
    EXPECT_EQ(0, test_tree.get_value());
}

TEST(TreeTest, CreatingFirstChild) {
    // Arrange
    _tree<int> test_tree;
    // Act
    test_tree.add(0);
    test_tree.add(5);
    test_tree.down();
    // Assert
    EXPECT_EQ(5, test_tree.get_value());
}

TEST(TreeTest, CreatingSecondChild) {
    // Arrange
    _tree<int> test_tree;
    // Act
    test_tree.add(0);
    test_tree.add(5);
    test_tree.down();
    test_tree.reset();
    test_tree.add(6);
    test_tree.down();
    test_tree.along();
    // Assert
    EXPECT_EQ(6, test_tree.get_value());
}

TEST(TreeTest, TestingChildLock) {
    // Arrange
    _tree<int> test_tree;
    // Act
    test_tree.add(0);
    test_tree.add(5);
    test_tree.down();
    test_tree.reset();
    test_tree.add(6);
    test_tree.down();
    test_tree.along();
    // Assert
    EXPECT_EQ(6, test_tree.get_value());
    test_tree.along();
    EXPECT_EQ(6, test_tree.get_value());
}

// Search tests

TEST(TreeTest, SearchInEmptyTree) {
    // Arrange
    _tree<int> test_tree;
    // Assert
    EXPECT_EQ(false, test_tree.search(0).success);
}

TEST(TreeTest, Search) {
    // Arrange
    _tree<int> test_tree;
    // Act
    test_tree.add(0);
    test_tree.add(1); test_tree.add(2); test_tree.add(3);
    test_tree.down();
    test_tree.add(4); test_tree.add(5);
    test_tree.along(); test_tree.along();
    test_tree.add(6);
    // Assert
    EXPECT_EQ(true, test_tree.search(0).success);
    EXPECT_EQ(0, test_tree.search(0).key);
    EXPECT_EQ(0, test_tree.search(0).value);
    EXPECT_EQ(true, test_tree.search(1).success);
    EXPECT_EQ(1, test_tree.search(1).key);
    EXPECT_EQ(1, test_tree.search(1).value);
    EXPECT_EQ(true, test_tree.search(2).success);
    EXPECT_EQ(2, test_tree.search(2).key);
    EXPECT_EQ(2, test_tree.search(2).value);
    EXPECT_EQ(true, test_tree.search(3).success);
    EXPECT_EQ(3, test_tree.search(3).key);
    EXPECT_EQ(3, test_tree.search(3).value);
    EXPECT_EQ(true, test_tree.search(4).success);
    EXPECT_EQ(4, test_tree.search(4).key);
    EXPECT_EQ(4, test_tree.search(4).value);
    EXPECT_EQ(true, test_tree.search(5).success);
    EXPECT_EQ(5, test_tree.search(5).key);
    EXPECT_EQ(5, test_tree.search(5).value);
    EXPECT_EQ(true, test_tree.search(0).success);
    EXPECT_EQ(6, test_tree.search(6).key);
    EXPECT_EQ(6, test_tree.search(6).value);
    EXPECT_EQ(false, test_tree.search(7).success);
}

// Destruction tests

TEST(TreeTest, DestructFirstChild) {
    // Arrange
    _tree<int> test_tree;
    // Act
    test_tree.add(0);
    test_tree.add(1); test_tree.add(2); test_tree.add(3);
    test_tree.down();
    test_tree.add(4); test_tree.add(5);
    test_tree.along(); test_tree.along();
    test_tree.add(6);
    test_tree.reset();
    test_tree.down();
    test_tree.destruct();
    // Assert
    EXPECT_EQ(0, test_tree.get_key());
    test_tree.down();
    EXPECT_EQ(2, test_tree.get_key());
}

TEST(TreeTest, DestructNonFirstChild) {
    // Arrange
    _tree<int> test_tree;
    // Act
    test_tree.add(0);
    test_tree.add(1); test_tree.add(2); test_tree.add(3);
    test_tree.down();
    test_tree.add(4); test_tree.add(5);
    test_tree.along(); test_tree.along();
    test_tree.add(6);
    test_tree.destruct();
    // Assert
    EXPECT_EQ(0, test_tree.get_key());
    // Act
    test_tree.down();
    test_tree.destruct();
    // Assert
    EXPECT_EQ(0, test_tree.get_key());
    // Act
    test_tree.down();
    // Assert
    EXPECT_EQ(2, test_tree.get_key());
}

TEST(TreeTest, FullDestruct) {
    // Arrange
    _tree<int> test_tree;
    // Act
    test_tree.add(0);
    test_tree.add(1); test_tree.add(2); test_tree.add(3);
    test_tree.down();
    test_tree.add(4); test_tree.add(5);
    test_tree.along(); test_tree.along();
    test_tree.add(6);
    test_tree.reset();
    test_tree.destruct();
    // Assert
    EXPECT_EQ(true, test_tree.is_empty());
}

// Copying tests

TEST(TreeTest, CopyingConstructor) {
    // Arrange
    _tree<int> test_tree1;
    // Act
    test_tree1.add(0);
    test_tree1.add(1); test_tree1.add(2); test_tree1.add(3);
    test_tree1.down();
    test_tree1.add(4); test_tree1.add(5);
    test_tree1.along(); test_tree1.along();
    test_tree1.add(6);
    _tree<int> test_tree2(test_tree1);
    test_tree1.reset(); test_tree2.reset();
    // Assert
    EXPECT_EQ(test_tree1.get_value(), test_tree2.get_value());
    test_tree1.down(), test_tree2.down();
    EXPECT_EQ(test_tree1.get_value(), test_tree2.get_value());
    // Act
    test_tree2.reset();
    test_tree2.destruct();
    test_tree2 = test_tree1;
    test_tree1.reset(); test_tree2.reset();
    // Assert
    EXPECT_EQ(test_tree1.get_value(), test_tree2.get_value());
    // Act
    test_tree1.down(), test_tree2.down();
    // Assert
    EXPECT_EQ(test_tree1.get_value(), test_tree2.get_value());
    // Act
    test_tree1.reset();
    test_tree1.destruct();
    // Assert
    EXPECT_EQ(false, test_tree2.is_empty());
    // Act
    test_tree2 = test_tree1;
    // Assert
    EXPECT_EQ(true, test_tree2.is_empty());
}

TEST(TreeTest, CopyingOperator) {
    // Arrange
    _tree<int> test_tree1;
    // Act
    test_tree1.add(0);
    test_tree1.add(1); test_tree1.add(2); test_tree1.add(3);
    test_tree1.down();
    test_tree1.add(4); test_tree1.add(5);
    test_tree1.along(); test_tree1.along();
    test_tree1.add(6);
    _tree<int> test_tree2;
    test_tree2 = test_tree1;
    test_tree1.reset(); test_tree2.reset();
    // Assert
    EXPECT_EQ(test_tree1.get_value(), test_tree2.get_value());
    test_tree1.down(), test_tree2.down();
    EXPECT_EQ(test_tree1.get_value(), test_tree2.get_value());
}

TEST(TreeTest, CopyingEmptyTree) {
    // Arrange
    _tree<int> test_tree1;
    // Act
    test_tree1.add(0);
    test_tree1.add(1); test_tree1.add(2); test_tree1.add(3);
    test_tree1.down();
    test_tree1.add(4); test_tree1.add(5);
    test_tree1.along(); test_tree1.along();
    test_tree1.add(6);
    _tree<int> test_tree2;
    // Assert
    EXPECT_EQ(false, test_tree1.is_empty());
    // Act
    test_tree1 = test_tree2;
    // Assert
    EXPECT_EQ(true, test_tree1.is_empty());
}

// Stress and exception tests

TEST(TreeTest, StressTest) {
    // Arrange
    struct test_tree_struct {
        char array[1000000];
    };
    test_tree_struct element;
    _tree<test_tree_struct> test_tree;
    // Act
    for (int i = 0; i < 1000; i++)  {
        test_tree.add(element);
        test_tree.destruct();
    }
    // Assert
    EXPECT_EQ(true, test_tree.is_empty());
}

TEST(TreeTest, Exception) {
    // Arrange
    _tree<int> test_tree;
    // Assert
    EXPECT_THROW(test_tree.get_key(), std::string);
    EXPECT_THROW(test_tree.get_value(), std::string);
    EXPECT_THROW(test_tree.destruct(), std::string);
}
