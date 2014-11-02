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

TEST(LeftistHeapTest, Can_Merge) {
    LeftistHeap xHeap, yHeap;

    xHeap.insert(11);
    yHeap.insert(22);
    xHeap.merge(&yHeap);

    for (int i = 1; i <= 2; ++i) {
        int key = xHeap.deleteMin();
        EXPECT_EQ(11*i, key);
    }

    EXPECT_TRUE(xHeap.isEmpty());
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

TEST(LeftistHeapTest, Can_Copy_And_Assign) {
    LeftistHeap xHeap;
    for (int i = 0; i < 1024; ++i) {
        xHeap.insert(i);
    }

    LeftistHeap yHeap = xHeap;
    LeftistHeap zHeap;
    zHeap = yHeap;

    for (int i = 0; i < 1024; ++i) {
        EXPECT_EQ(i, yHeap.deleteMin());
        EXPECT_EQ(i, zHeap.deleteMin());
    }
    EXPECT_TRUE(yHeap.isEmpty());
    EXPECT_TRUE(zHeap.isEmpty());
}

TEST(StressTest, A_Lot_Of_Insertions_And_Deletions_Dont_Change_Heap_Size) {
    LeftistHeap lHeap;
    for (int i = 0; i < 1024; ++i) {
        for (int j = 0; j < 1024; ++j) {
            lHeap.insert(j);
        }
        for (int j = 0; j < 1024; ++j) {
            lHeap.deleteMin();
        }
    }
    EXPECT_TRUE(lHeap.isEmpty());
}
