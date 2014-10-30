// Copyright 2014 Gladilov Gleb

#ifndef CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_H_
#define CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_H_

typedef double RealType;
typedef double ImaginaryType;

class Complex {
// members
 private:
    RealType real_ = 0;
    ImaginaryType imaginary_ = 0;

 public:
    // constructors
    Complex();
    Complex(const RealType real, const ImaginaryType imaginary);
    Complex(const Complex& complex);

    // getters for real and imaginary
    RealType GetReal() const;
    ImaginaryType GetImaginary() const;

    // setters for real and imaginary
    void SetReal(const RealType real);
    void SetImaginary(const ImaginaryType imaginary);

    // sum and differenece
    void Add(const Complex& complex);
    void Difference(const Complex& complex);

    // multiplication and division
    void Multiplication(const Complex& complex);
    void Division(const Complex& complex);
};

#endif  // CODE_GLADILOV_GLEB_INCLUDE_COMPLEXCALCULATOR_H_

