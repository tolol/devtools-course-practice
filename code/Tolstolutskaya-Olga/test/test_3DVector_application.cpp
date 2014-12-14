// Copyright 2014 Tolstolutskaya Olga

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/3DVector_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

#define EPSILON 1e-5

class AppTest : public ::testing::Test {
 protected:
    virtual void SetUp() {
        args.clear();
    }
    // virtual void TearDown() {}

    void Act(vector<string> args_) {
        vector<const char*> starts;
        starts.push_back("appname");

        for (size_t i = 0; i < args_.size(); ++i) {
            starts.push_back(args_[i].c_str());
        }
        const char** argv = &starts.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    VectorApplication app_;
    string output_;
    vector<string> args;
};

TEST_F(AppTest, Do_Print_Help_Without_Arguments) {
    Act(args);

    Assert("This is a Vector application\\..*");
}

TEST_F(AppTest, Is_Checking_Number_Of_Arguments) {
    args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 5 or 8 arguments\\..*");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Format) {
    args = {"Normalize", "pi", "2", "3"};

    Act(args);
    
    Assert("Wrong number format!.*");
}

TEST_F(AppTest, Can_Detect_Wrong_Operation_Format) {
    args = {"Sum", "1", "2", "3"};

    Act(args);
    
    Assert("Wrong operation!");
}

TEST_F(AppTest, Correct_Computation_Norm) {
    args = {"Norm", "1", "2", "3"};

    Act(args);
    
    Assert("Result = 3.741657");
}


TEST_F(AppTest, Correct_Computation_Normalize) {
    args = {"Normalize", "1", "2", "3"};

    Act(args);
    
    Assert("Result = 0.267261 0.534522 0.801784");
}

TEST_F(AppTest, Correct_Computation_Normalize2) {
    args = {"Normalize", "-1", "-2", "-3"};

    Act(args);
    
    Assert("Result = -0.267261 -0.534522 -0.801784");
}

TEST_F(AppTest, Correct_Computation_ScalarProduct) {
    args = {"ScalarProduct", "1", "2", "3", "2", "1", "-2"};

    Act(args);
    
    Assert("Result = -2");
}

TEST_F(AppTest, Correct_Computation_VectorProduct) {
    args = {"VectorProduct", "1", "2", "3", "2", "1", "-2"};

    Act(args);
    
    Assert("Result = -7 8 -3");
}
