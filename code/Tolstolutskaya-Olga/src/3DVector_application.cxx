// Copyright 2014 Tolstolutskaya Olga

#include "include/3DVector.h"
#include "include/3DVector_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iomanip>

Expression::Expression() : arg1(Vector3d()), arg2(Vector3d()), operation("") {}
VectorApplication::VectorApplication() : message_("") {}

void VectorApplication::help(const char* appname, const char* message = "") {
    message_ = std::string(message)
             + std::string("This is a Vector application.\n\n")
             + "Please provide arguments in the following format:\n\n"
             + "  $ " + appname + " <operation> <argument1> <argument2>"
             + " <argument3>\n\nWhere arguments are integer numbers, "
             + "and <operation> is one of 'Normalize' or 'Norm'.\n"
             + "or:\n\n"
             + "  $ " + appname + "<operation> <argument1> <argument2> "
             + "<argument3> <argument4> <argument5> <argument6>\n\nWhere "
             + "arguments are integer numbers, and <operation> is one of "
             + "'ScalarProduct' or 'VectorProduct'.\n";
}

double parseDouble(const char* arg);
double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

     if (end[0])
         throw "Wrong number format\n";
     return value;
}

bool VectorApplication::parseArguments(int argc, const char** argv,
                                           Expression* expression) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5 && argc != 8) {
        help(argv[0], "ERROR: Should be 5 or 8 arguments.\n\n");
        return false;
    }

    if (argc == 5) {
        try {
            double a = (parseDouble(argv[2]));
            double b = (parseDouble(argv[3]));
            double c = (parseDouble(argv[4]));
            expression->arg1(a, b, c);
         }
        catch(...) {
            message_ = "Wrong number format!\n";
            return false;
        }
    }

    if (argc == 8) {
        try {
            double a = (parseDouble(argv[2]));
            double b = (parseDouble(argv[3]));
            double c = (parseDouble(argv[4]));
            double d = (parseDouble(argv[5]));
            double e = (parseDouble(argv[6]));
            double f = (parseDouble(argv[7]));
            expression->arg1(a, b, c);
            expression->arg2(d, e, f);
         }
        catch(...) {
            message_ = "Wrong number format!\n";
            return false;
        }
    }

    const char* op = argv[1];
    if (strcmp(op, "Normalize") && strcmp(op, "Norm")
    && strcmp(op, "ScalarProduct")
        &&strcmp(op, "VectorProduct")) {
        message_ = std::string(op) + " - Wrong operation!\n";
        return false;
    } else {
        expression->operation = op;
    }

    return true;
}

std::string VectorApplication::operator()(int argc, const char** argv) {
    Expression expr;

    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true)
        return message_;

    std::ostringstream stream;
    stream << expr.operation.c_str();
    stream << "Result = ";
    stream << std::setprecision(6);
    if (!strcmp("Normalize", expr.operation.c_str())) {
        expr.arg1.Normalize();

        stream << expr.arg1.GetA() << " ";
        stream << expr.arg1.GetB() << " ";
        stream << expr.arg1.GetC();
    }

    if (!strcmp(expr.operation.c_str(), "Norm")) {
        stream << std::setprecision(7) << expr.arg1.Norm();
    }
    if (!strcmp(expr.operation.c_str(), "ScalarProduct")) {
        stream << std::setprecision(7) << expr.arg1.ScalarProduct(expr.arg2);
    }
    if (!strcmp(expr.operation.c_str(), "VectorProduct")) {
        Vector3d v = expr.arg1.VectorProduct(expr.arg2);
        stream << v.GetA() << " ";
        stream << v.GetB() << " ";
        stream << v.GetC();
    }

    message_ = stream.str();

    return message_;
}
