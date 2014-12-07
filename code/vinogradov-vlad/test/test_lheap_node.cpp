// Copyright 2014 Vlad Vinogradov

#include <gtest/gtest.h>

#include <string>

#include "include/leftistheap.h"

TEST(LHeapNodeTest, Can_Create) {
    // Arrange & Act
    LHeapNode node(11);

    // Assert
    EXPECT_EQ(11, node._key);
    EXPECT_EQ(NULL, node._leftChild);
    EXPECT_EQ(NULL, node._rightChild);
}

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
