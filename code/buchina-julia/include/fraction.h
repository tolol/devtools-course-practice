// Copyright 2014 Julia Buchina

#ifndef CODE_BUCHINA_JULIA_INCLUDE_FRACTION_H_
#define CODE_BUCHINA_JULIA_INCLUDE_FRACTION_H_

class Fraction {
 private:
    int numerator;
    int denominator;
 protected:
    void setNumerator(int _numerator);
    void setDenominator(int _denominator);
 public:
    Fraction();
    Fraction(int _numerator, int _denominator);
    Fraction(const Fraction& fraction);
    ~Fraction();

    int getNumerator();
    int getDenominator();

    const Fraction& operator=(const Fraction& fraction);
    Fraction& operator+(const Fraction& a);
    Fraction& operator-(const Fraction& a);
    Fraction& operator*(const Fraction& a);
    Fraction& operator/(const Fraction& a);
};

#endif  // CODE_BUCHINA_JULIA_INCLUDE_FRACTION_H_
