// Copyright 2014 Vlad Vinogradov

#include <gtest/gtest.h>

#include <string>

#include "include/leftistheap.h"

TEST(LHeapNodeTest, Can_Merge) {
    // Arrange
    LHeapNode xHeap(11);
    LHeapNode yHeap(22);

    // Act
    LHeapNode* zHeap = LHeapNode::merge(&xHeap, &yHeap);

    // Assert
    EXPECT_EQ(11, zHeap->_key);
    EXPECT_EQ(22, zHeap->_leftChild->_key);
}

TEST(LeftistHeapTest, Can_Say_Is_Empty) {
    // Arrange & Act
    LeftistHeap lHeap;

    // Assert
    EXPECT_TRUE(lHeap.isEmpty());
}

TEST(LeftistHeapTest, Can_Merge) {
    // Arrange
    LeftistHeap xHeap, yHeap;
    xHeap.insert(11);
    yHeap.insert(22);

    // Act
    xHeap.merge(&yHeap);

    // Assert
    EXPECT_EQ(11, xHeap.deleteMin());
    EXPECT_EQ(22, xHeap.deleteMin());
}

TEST(LeftistHeapTest, Can_Insert_And_Find_Min) {
    // Arrange
    LeftistHeap lHeap;
    for (int i = 10; i < 15; ++i) {
        lHeap.insert(i);
    }

    // Act & Assert
    EXPECT_EQ(10, lHeap.findMin());
}

TEST(LeftistHeapTest, Can_Insert_And_Delete_Min) {
    // Arrange
    LeftistHeap lHeap;
    for (int i = 10; i < 15; ++i) {
        lHeap.insert(i);
    }

    // Act & Assert
    EXPECT_EQ(10, lHeap.deleteMin());
}

TEST(LeftistHeapTest, Can_Throw_Exception_When_Find_Min_In_Empty_Heap) {
    // Arrange
    LeftistHeap lHeap;

    // Act & Assert
    EXPECT_THROW(lHeap.findMin(), std::string);
}

TEST(LeftistHeapTest, Can_Throw_Exception_When_Delete_Min_In_Empty_Heap) {
    // Arrange
    LeftistHeap lHeap;

    // Act & Assert
    EXPECT_THROW(lHeap.deleteMin(), std::string);
}

TEST(LeftistHeapTest, Heap_Is_Empty_After_Inserting_And_Deleting_Min) {
    // Arrange
    LeftistHeap lHeap;

    // Act
    lHeap.insert(123);
    lHeap.deleteMin();

    // Assert
    EXPECT_TRUE(lHeap.isEmpty());
}

TEST(LeftistHeapTest, Can_Copy) {
    // Arrange
    LeftistHeap xHeap;
    for (int i = 0; i < 1024; ++i) {
        xHeap.insert(i);
    }

    // Act
    LeftistHeap yHeap = xHeap;

    // Assert
    for (int i = 0; i < 1024; ++i) {
        EXPECT_EQ(i, yHeap.deleteMin());
    }
}

TEST(LeftistHeapTest, Can_Assign) {
    // Arrange
    LeftistHeap xHeap;
    for (int i = 0; i < 1024; ++i) {
        xHeap.insert(i);
    }

    // Act
    LeftistHeap yHeap;
    yHeap = xHeap;

    // Assert
    for (int i = 0; i < 1024; ++i) {
        EXPECT_EQ(i, yHeap.deleteMin());
    }
}

TEST(StressTest, A_Lot_Of_Insertions_And_Deletions_Dont_Change_Heap_Size) {
    // Arrange
    LeftistHeap lHeap;

    // Act
    for (int i = 0; i < 1024; ++i) {
        for (int j = 0; j < 1024; ++j) {
            lHeap.insert(j);
        }
        for (int j = 0; j < 1024; ++j) {
            lHeap.deleteMin();
        }
    }

    // Assert
    EXPECT_TRUE(lHeap.isEmpty());
}
