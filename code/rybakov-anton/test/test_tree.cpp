// Copyright 2014 Anton Rybakov

#include <gtest/gtest.h>

#include <string>
#include "include/tree.h"

class TreeTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    _tree<int> s;
};

TEST_F(TreeTest, Basic) {
    s.add(0);
    EXPECT_EQ(0, s.get_value());
    s.add(5);
    s.down();
    EXPECT_EQ(5, s.get_value());
    s.reset();
    EXPECT_EQ(0, s.get_key());
    s.add(6);
    s.down();
    s.along();
    EXPECT_EQ(6, s.get_value());
    s.along();
    EXPECT_EQ(6, s.get_value());
}

TEST_F(TreeTest, Search) {
    EXPECT_EQ(false, s.search(0).success);
    s.add(0);
    s.add(1);
    s.add(2);
    s.add(3);
    s.down();
    s.add(4);
    s.add(5);
    s.along();
    s.along();
    s.add(6);
    EXPECT_EQ(0, s.search(0).key);
    EXPECT_EQ(1, s.search(1).key);
    EXPECT_EQ(2, s.search(2).key);
    EXPECT_EQ(3, s.search(3).key);
    EXPECT_EQ(4, s.search(4).key);
    EXPECT_EQ(5, s.search(5).key);
    EXPECT_EQ(6, s.search(6).key);
    EXPECT_EQ(false, s.search(7).success);
}

TEST_F(TreeTest, Destruct) {
    s.add(0);
    s.add(1);
    s.add(2);
    s.add(3);
    s.down();
    s.add(4);
    s.add(5);
    s.along();
    s.along();
    s.add(6);
    s.reset();
    s.down();
    s.along();
    s.along();
    s.reset();
    s.down();
    EXPECT_EQ(true, s.destruct());
}
