// Copyright 2014 Gladilov Gleb

#include "include/complexcalculator.h"

#include <stdbool.h>
#include <string>
#include <limits>

bool CompareRealWithZero(const RealType real);
bool CompareRealWithZero(const RealType real) {
    if (real < std::numeric_limits<RealType>::epsilon() &&
        real > -std::numeric_limits<RealType>::epsilon())
        return true;
    else
        return false;
}
bool CompareImaginaryWithZero(const ImaginaryType imaginary);
bool CompareImaginaryWithZero(const ImaginaryType imaginary) {
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

Complex::Complex(const Complex& complex) : real_(complex.GetReal()),
                                           imaginary_(complex.GetImaginary()) {}

RealType Complex::GetReal() const {
    return real_;
}
ImaginaryType Complex::GetImaginary() const {
    return imaginary_;
}

void Complex::SetReal(const RealType real) {
    real_ = real;
}
void Complex::SetImaginary(const ImaginaryType imaginary) {
    imaginary_ = imaginary;
}

void Complex::Add(const Complex& complex) {
    real_ += complex.GetReal();
    imaginary_ += complex.GetImaginary();
}
void Complex::Difference(const Complex& complex) {
    real_ -= complex.GetReal();
    imaginary_ -= complex.GetImaginary();
}

void Complex::Multiplication(const Complex& complex) {
    RealType myReal = real_;
    ImaginaryType myImaginary = imaginary_;

    real_ = myReal * complex.GetReal() -
                  myImaginary * complex.GetImaginary();
    imaginary_ = myImaginary * complex.GetReal() +
                       myReal * complex.GetImaginary();
}
void Complex::Division(const Complex& complex) {
    if (CompareRealWithZero(complex.GetReal()) &&
        CompareImaginaryWithZero(complex.GetImaginary())) {
        throw std::string("Can't divide by zero");
    } else {
        RealType myReal = real_;
        ImaginaryType myImaginary = imaginary_;

        double dnmntr = 1.0 / (complex.GetReal() * complex.GetReal() +
                               complex.GetImaginary() * complex.GetImaginary());

        real_ = dnmntr * myReal * complex.GetReal() +
                      dnmntr * myImaginary * complex.GetImaginary();

        imaginary_ = dnmntr * complex.GetReal() * myImaginary -
                           dnmntr * complex.GetImaginary() * myReal;
    }
}
