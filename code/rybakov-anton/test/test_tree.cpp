// Copyright 2014 Anton Rybakov

#include <gtest/gtest.h>

#include <string>
#include "include/tree.h"

class TreeTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}
};

TEST_F(TreeTest, Basic) {
    _tree<int> test;
    test.add(0);
    EXPECT_EQ(0, test.get_value());
    test.add(5);
    test.down();
    EXPECT_EQ(5, test.get_value());
    test.reset();
    EXPECT_EQ(0, test.get_key());
    test.add(6);
    test.down();
    test.along();
    EXPECT_EQ(6, test.get_value());
    test.along();
    EXPECT_EQ(6, test.get_value());
}

TEST_F(TreeTest, Search) {
    _tree<int> test;
    EXPECT_EQ(false, test.search(0).success);
    test.add(0);
    test.add(1); test.add(2); test.add(3);
    test.down();
    test.add(4); test.add(5);
    test.along(); test.along();
    test.add(6);
    EXPECT_EQ(true, test.search(0).success);
    EXPECT_EQ(0, test.search(0).key);
    EXPECT_EQ(0, test.search(0).value);
    EXPECT_EQ(true, test.search(1).success);
    EXPECT_EQ(1, test.search(1).key);
    EXPECT_EQ(1, test.search(1).value);
    EXPECT_EQ(true, test.search(2).success);
    EXPECT_EQ(2, test.search(2).key);
    EXPECT_EQ(2, test.search(2).value);
    EXPECT_EQ(true, test.search(3).success);
    EXPECT_EQ(3, test.search(3).key);
    EXPECT_EQ(3, test.search(3).value);
    EXPECT_EQ(true, test.search(4).success);
    EXPECT_EQ(4, test.search(4).key);
    EXPECT_EQ(4, test.search(4).value);
    EXPECT_EQ(true, test.search(5).success);
    EXPECT_EQ(5, test.search(5).key);
    EXPECT_EQ(5, test.search(5).value);
    EXPECT_EQ(true, test.search(0).success);
    EXPECT_EQ(6, test.search(6).key);
    EXPECT_EQ(6, test.search(6).value);
    EXPECT_EQ(false, test.search(7).success);
}

TEST_F(TreeTest, Destruct) {
    _tree<int> test;
    test.add(0);
    test.add(1); test.add(2); test.add(3);
    test.down();
    test.add(4); test.add(5);
    test.along(); test.along();
    test.add(6);
    test.reset();
    test.down();
    test.destruct();
    EXPECT_EQ(0, test.get_key());
    test.down();
    EXPECT_EQ(2, test.get_key());
    test.reset();
    test.destruct();
    EXPECT_EQ(true, test.is_empty());
}

TEST_F(TreeTest, Copying) {
    _tree<int> test1;
    test1.add(0);
    test1.add(1); test1.add(2); test1.add(3);
    test1.down();
    test1.add(4); test1.add(5);
    test1.along(); test1.along();
    test1.add(6);
    _tree<int> test2(test1);
    test1.reset(); test2.reset();
    EXPECT_EQ(test1.get_value(), test2.get_value());
    test1.down(), test2.down();
    EXPECT_EQ(test1.get_value(), test2.get_value());
    test2.reset();
    test2.destruct();
    test2 = test1;
    test1.reset(); test2.reset();
    EXPECT_EQ(test1.get_value(), test2.get_value());
    test1.down(), test2.down();
    EXPECT_EQ(test1.get_value(), test2.get_value());
}

TEST_F(TreeTest, StressTest) {
    struct test_struct {
        char array[1000000];
    };
    test_struct element;
    _tree<test_struct> test;
    for (int i = 0; i < 10; i++)  {
        test.add(element);
        test.destruct();
    }
    EXPECT_EQ(true, test.is_empty());
}

TEST_F(TreeTest, Exception) {
    _tree<int> test;
    EXPECT_THROW(test.get_key(), std::string);
    EXPECT_THROW(test.get_value(), std::string);
    EXPECT_THROW(test.destruct(), std::string);
}
