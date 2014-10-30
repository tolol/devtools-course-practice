// Copyright 2014 Gladilov Gleb

#include "include/complexcalculator.h"

#include <string>

Complex::Complex() {}
Complex::Complex(const RealType real, const ImaginaryType imaginary) {
    this->real_ = real;
    this->imaginary_ = imaginary;
}

Complex::Complex(const Complex& complex) {
    this->real_ = complex.GetReal();
    this->imaginary_ = complex.GetImaginary();
}

RealType Complex::GetReal() const {
    return this->real_;
}
ImaginaryType Complex::GetImaginary() const {
    return this->imaginary_;
}

void Complex::SetReal(const RealType real) {
    this->real_ = real;
}
void Complex::SetImaginary(const ImaginaryType imaginary) {
    this->imaginary_ = imaginary;
}

void Complex::Add(const Complex& complex) {
    this->real_ += complex.GetReal();
    this->imaginary_ += complex.GetReal();
}
void Complex::Difference(const Complex& complex) {
    this->real_ -= complex.GetReal();
    this->imaginary_ -= complex.GetImaginary();
}

void Complex::Multiplication(const Complex& complex) {
    RealType myReal = this->real_;
    ImaginaryType myImaginary = this->imaginary_;

    this->real_ = myReal * complex.GetReal() -
                  myImaginary * complex.GetImaginary();
    this->imaginary_ = myImaginary * complex.GetReal() +
                       myReal * complex.GetImaginary();
}
void Complex::Division(const Complex& complex) {
    if (complex.GetReal() == 0 && complex.GetImaginary() == 0) {
        throw std::string("Can't divide by zero");
    } else {
        RealType myReal = this->real_;
        ImaginaryType myImaginary = this->imaginary_;

        double dnmntr = 1.0 / (complex.GetReal() * complex.GetReal() +
                               complex.GetImaginary() * complex.GetImaginary());

        this->real_ = dnmntr * myReal * complex.GetReal() +
                      dnmntr * myImaginary * complex.GetImaginary();

        this->imaginary_ = dnmntr * complex.GetReal() * myImaginary -
                           dnmntr * complex.GetImaginary() * myReal;
    }
}
