// Copyright 2014 Gladilov Gleb

#ifndef CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_H_
#define CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_H_

typedef double RealType;
typedef double ImaginaryType;

class Complex {
// members
 private:
    RealType real_;
    ImaginaryType imaginary_;

 public:
    // constructors
    Complex();
    Complex(const RealType real, const ImaginaryType imaginary);
    Complex(const Complex& complex);

    // getters for real and imaginary
    RealType getReal() const;
    ImaginaryType getImaginary() const;

    // setters for real and imaginary
    void setReal(const RealType real);
    void setImaginary(const ImaginaryType imaginary);

    // sum and differenece
    void add(const Complex& complex);
    void difference(const Complex& complex);

    // multiplication and division
    void multiplication(const Complex& complex);
    void division(const Complex& complex);
};

#endif  // CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_H_

