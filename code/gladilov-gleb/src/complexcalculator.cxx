// Copyright 2014 Gladilov Gleb

#include "include/complexcalculator.h"

#include <stdbool.h>
#include <string>
#include <limits>

bool compareRealWithZero(const RealType real);
bool compareRealWithZero(const RealType real) {
    if (real < std::numeric_limits<RealType>::epsilon() &&
        real > -std::numeric_limits<RealType>::epsilon())
        return true;
    else
        return false;
}
bool compareImaginaryWithZero(const ImaginaryType imaginary);
bool compareImaginaryWithZero(const ImaginaryType imaginary) {
    if (imaginary < std::numeric_limits<ImaginaryType>::epsilon() &&
        imaginary > -std::numeric_limits<ImaginaryType>::epsilon())
        return true;
    else
        return false;
}

Complex::Complex() : real_(0), imaginary_(0) {}
Complex::Complex(const RealType real,
                 const ImaginaryType imaginary) : real_(real),
                                                  imaginary_(imaginary) {}

Complex::Complex(const Complex& complex) : real_(complex.getReal()),
                                           imaginary_(complex.getImaginary()) {}

RealType Complex::getReal() const {
    return real_;
}
ImaginaryType Complex::getImaginary() const {
    return imaginary_;
}

void Complex::setReal(const RealType real) {
    real_ = real;
}
void Complex::setImaginary(const ImaginaryType imaginary) {
    imaginary_ = imaginary;
}

void Complex::add(const Complex& complex) {
    real_ += complex.getReal();
    imaginary_ += complex.getImaginary();
}
void Complex::difference(const Complex& complex) {
    real_ -= complex.getReal();
    imaginary_ -= complex.getImaginary();
}

void Complex::multiplication(const Complex& complex) {
    RealType myReal = real_;
    ImaginaryType myImaginary = imaginary_;

    real_ = myReal * complex.getReal() -
                  myImaginary * complex.getImaginary();
    imaginary_ = myImaginary * complex.getReal() +
                       myReal * complex.getImaginary();
}
void Complex::division(const Complex& complex) {
    if (compareRealWithZero(complex.getReal()) &&
        compareImaginaryWithZero(complex.getImaginary())) {
        throw std::string("Can't divide by zero");
    } else {
        RealType myReal = real_;
        ImaginaryType myImaginary = imaginary_;

        double dnmntr = 1.0 / (complex.getReal() * complex.getReal() +
                               complex.getImaginary() * complex.getImaginary());

        real_ = dnmntr * myReal * complex.getReal() +
                      dnmntr * myImaginary * complex.getImaginary();

        imaginary_ = dnmntr * complex.getReal() * myImaginary -
                           dnmntr * complex.getImaginary() * myReal;
    }
}
