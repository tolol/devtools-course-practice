// Copyright 2014 Julia Buchina

#ifndef CODE_BUCHINA_JULIA_INCLUDE_FRACTION_H_
#define CODE_BUCHINA_JULIA_INCLUDE_FRACTION_H_

class Fraction {
 private:
    int numerator;
    int denominator;
 public:
    Fraction();
    Fraction(int _numerator, int _denominator);
    Fraction(const Fraction& a);
    ~Fraction();

    Fraction& operator=(const Fraction& a);

    void setNumerator(int _numerator);
    void setDenominator(int _denominator);

    int getNumerator() const;
    int getDenominator() const;
};

Fraction operator+(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a, const Fraction& b);
Fraction operator*(const Fraction& a, const Fraction& b);
Fraction operator/(const Fraction& a, const Fraction& b);

#endif  // CODE_BUCHINA_JULIA_INCLUDE_FRACTION_H_
