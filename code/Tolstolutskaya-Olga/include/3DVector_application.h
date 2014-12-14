// Copyright 2014 Tolstolutskaya Olga

#ifndef CODE_TOLSTOLUTSKAYA_OLGA_INCLUDE_3DVECTOR_APPLICATION_H_
#define CODE_TOLSTOLUTSKAYA_OLGA_INCLUDE_3DVECTOR_APPLICATION_H_

#include <string>
#include "include/3DVector.h"

#pragma pack(push, 1)
class Expression {
 public:
    Vector3d arg1;
    Vector3d arg2;
    std::string operation;
    Expression();
};
#pragma pack(pop)

class VectorApplication {
 public:
    VectorApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv, Expression* expr);
};

#endif  // CODE_TOLSTOLUTSKAYA_OLGA_INCLUDE_3DVECTOR_APPLICATION_H_
