// Copyright 2014 Tolstolutskaya Olga

#include <stdio.h>
#include <string>

#include "include/3DVector.h"
#include "include/3DVector_application.h"

int main(int argc, const char** argv) {
    VectorApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
