// Copyright 2014 Gladilov Gleb

#include "include/complexcalculator.h"

#include <stdbool.h>
#include <string>
#include <limits>

bool compareComplexWithZero(const Complex& complex);
bool compareComplexWithZero(const Complex& complex) {
    if (complex.getReal() < std::numeric_limits<ValueType>::epsilon() &&
        complex.getReal() > -std::numeric_limits<ValueType>::epsilon() &&

        complex.getImaginary() < std::numeric_limits<ValueType>::epsilon() &&
        complex.getImaginary() > -std::numeric_limits<ValueType>::epsilon())
        return true;
    else
        return false;
}

Complex::Complex() : real_(0), imaginary_(0) {}
Complex::Complex(const ValueType real,
                 const ValueType imaginary) : real_(real),
                                                  imaginary_(imaginary) {}

Complex::Complex(const Complex& complex) : real_(complex.getReal()),
                                           imaginary_(complex.getImaginary()) {}

ValueType Complex::getReal() const {
    return real_;
}
ValueType Complex::getImaginary() const {
    return imaginary_;
}

void Complex::setReal(const ValueType real) {
    real_ = real;
}
void Complex::setImaginary(const ValueType imaginary) {
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
    ValueType myReal = real_;
    ValueType myImaginary = imaginary_;

    real_ = myReal * complex.getReal() -
                  myImaginary * complex.getImaginary();
    imaginary_ = myImaginary * complex.getReal() +
                       myReal * complex.getImaginary();
}
void Complex::division(const Complex& complex) {
    if (compareComplexWithZero(complex)) {
        throw std::string("Can't divide by zero");
    } else {
        ValueType myReal = real_;
        ValueType myImaginary = imaginary_;

        double dnmntr = 1.0 / (complex.getReal() * complex.getReal() +
                               complex.getImaginary() * complex.getImaginary());

        real_ = dnmntr * myReal * complex.getReal() +
                      dnmntr * myImaginary * complex.getImaginary();

        imaginary_ = dnmntr * complex.getReal() * myImaginary -
                           dnmntr * complex.getImaginary() * myReal;
    }
}
