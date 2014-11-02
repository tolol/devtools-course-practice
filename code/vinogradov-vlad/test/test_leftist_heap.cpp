// Copyright 2014 Vlad Vinogradov

#include <gtest/gtest.h>

#include <string>

#include "include/leftistheap.h"

class LeftistHeapTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}
};

TEST(LeftistHeapTest, Can_Say_Is_Empty) {
    LeftistHeap lHeap;

    EXPECT_TRUE(lHeap.isEmpty());
}

TEST(LeftistHeapTest, Can_Insert_And_Find_Min_And_Delete_Min) {
    LeftistHeap lHeap;

    for (int i = 10; i < 15; ++i) {
        lHeap.insert(i);
    }

    EXPECT_FALSE(lHeap.isEmpty());
    EXPECT_EQ(10, lHeap.findMin());
    EXPECT_EQ(10, lHeap.deleteMin());
    EXPECT_FALSE(lHeap.isEmpty());
    EXPECT_EQ(11, lHeap.findMin());
}

TEST(LeftistHeapTest, Can_Throw_Exception_When_Find_Min_In_Empty_Heap) {
    LeftistHeap lHeap;

    EXPECT_THROW(lHeap.findMin(), std::string);
}

TEST(LeftistHeapTest, Can_Throw_Exception_When_Delete_Min_In_Empty_Heap) {
    LeftistHeap lHeap;

    EXPECT_THROW(lHeap.deleteMin(), std::string);
}

TEST(LeftistHeapTest, Heap_Is_Empty_After_Inserting_And_Deleting_Min) {
    LeftistHeap lHeap;

    lHeap.insert(123);
    lHeap.deleteMin();

    EXPECT_TRUE(lHeap.isEmpty());
}
