// Copyright 2013 Kirill Kornyakov

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/simplecalculator_application.h"

using ::testing::internal::RE;

class AppTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    void Act(std::vector<std::string> args) {
        std::vector<const char*> starts;
        starts.push_back("appname");

        for (size_t i = 0; i < args.size(); ++i) {
            starts.push_back(args[i].c_str());
        }
        const char** argv = &starts.front();
        int argc = static_cast<int>(args.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        std::cout << output_;
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    CalculatorApplication app_;
    std::string output_;
};

TEST_F(AppTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args;

    Act(args);

    Assert("This is a simple calculator application\\..*");
}

TEST_F(AppTest, Is_Checking_Number_Of_Arguments) {
    std::vector<std::string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Format) {
    std::vector<std::string> args = {"1", "pi", "+"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(AppTest, Can_Detect_Wrong_Operation_Format) {
    std::vector<std::string> args = {"1", "1", "garbage"};

    Act(args);

    Assert("Wrong operation!");
}

TEST_F(AppTest, Can_Add_Positive_Numbers) {
    std::vector<std::string> args = {"2", "3", "+"};

    Act(args);

    Assert("Result = 5");
}

TEST_F(AppTest, Can_Sub_Large_Negative_Numbers) {
    std::vector<std::string> args = {"-200000", "-3000000", "-"};

    Act(args);

    Assert("Result = 2800000");
}
