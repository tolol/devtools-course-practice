// Copyright 2014 Julia Buchina

#include "include/fraction.h"

#include <stdint.h>
#include <limits.h>
#include <string>

#define ABS(x) (((x) > 0) ? (x) : -(x))

Fraction::Fraction(): numerator(0), denominator(1) {}
Fraction::~Fraction() {}

void CheckValue(int64_t a);
int64_t GCD(int64_t a, int64_t b);

void CheckValue(int64_t a) {
    if (a > INT_MAX)
        throw std::string("Value is larger than INT_MAX");
    else if (a < INT_MIN)
        throw std::string("Value is less than INT_MIN");
}

int64_t GCD(int64_t a, int64_t b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

Fraction::Fraction(int _numerator, int _denominator): numerator(0),
                                                    denominator(1) {
    if (_denominator != 0) {
        numerator = _numerator;
        denominator = _denominator;
    } else {
        throw std::string("Can't divide by zero");
    }
}

Fraction::Fraction(const Fraction& a): numerator(a.getNumerator()),
    denominator(a.getDenominator()) {}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setNumerator(int _numerator) {
    numerator = _numerator;
}

void Fraction::setDenominator(int _denominator) {
    if (_denominator != 0) {
        denominator = _denominator;
    } else {
        throw std::string("Can't divide by zero");
    }
}

Fraction& Fraction::operator=(const Fraction& a) {
    numerator = a.getNumerator();
    denominator = a.getDenominator();
    return *this;
}

Fraction operator+(const Fraction& a, const Fraction& b) {
    Fraction tmp;
    int64_t tmpNumerator = static_cast<int64_t>(a.getNumerator()) *
                           static_cast<int64_t>(b.getDenominator()) +
                           static_cast<int64_t>(b.getNumerator()) *
                           static_cast<int64_t>(a.getDenominator());
    int64_t tmpDenominator = static_cast<int64_t>(a.getDenominator()) *
                             static_cast<int64_t>(b.getDenominator());

    int64_t tmpGCD = GCD(ABS(tmpNumerator), ABS(tmpDenominator));
    tmpNumerator = tmpNumerator / tmpGCD;
    tmpDenominator = tmpDenominator / tmpGCD;

    CheckValue(tmpNumerator);
    CheckValue(tmpDenominator);

    tmp.setNumerator(static_cast<int>(tmpNumerator));
    tmp.setDenominator(static_cast<int>(tmpDenominator));
    return tmp;
}

Fraction operator-(const Fraction& a, const Fraction& b) {
    Fraction tmp;
    int64_t tmpNumerator = static_cast<int64_t>(a.getNumerator()) *
                           static_cast<int64_t>(b.getDenominator()) -
                           static_cast<int64_t>(b.getNumerator()) *
                           static_cast<int64_t>(a.getDenominator());
    int64_t tmpDenominator = static_cast<int64_t>(a.getDenominator()) *
                             static_cast<int64_t>(b.getDenominator());

    int64_t tmpGCD = GCD(ABS(tmpNumerator), ABS(tmpDenominator));
    tmpNumerator = tmpNumerator / tmpGCD;
    tmpDenominator = tmpDenominator / tmpGCD;

    CheckValue(tmpNumerator);
    CheckValue(tmpDenominator);

    tmp.setNumerator(static_cast<int>(tmpNumerator));
    tmp.setDenominator(static_cast<int>(tmpDenominator));
    return tmp;
}

Fraction operator*(const Fraction& a, const Fraction& b) {
    Fraction tmp;
    int64_t tmpNumerator = static_cast<int64_t>(a.getNumerator()) *
                           static_cast<int64_t>(b.getNumerator());
    int64_t tmpDenominator = static_cast<int64_t>(a.getDenominator()) *
                             static_cast<int64_t>(b.getDenominator());

    int64_t tmpGCD = GCD(ABS(tmpNumerator), ABS(tmpDenominator));
    tmpNumerator = tmpNumerator / tmpGCD;
    tmpDenominator = tmpDenominator / tmpGCD;

    CheckValue(tmpNumerator);
    CheckValue(tmpDenominator);

    tmp.setNumerator(static_cast<int>(tmpNumerator));
    tmp.setDenominator(static_cast<int>(tmpDenominator));
    return tmp;
}

Fraction operator/(const Fraction& a, const Fraction& b) {
    Fraction tmp;
    int64_t tmpNumerator = static_cast<int64_t>(a.getNumerator()) *
                           static_cast<int64_t>(b.getDenominator());
    int64_t tmpDenominator = static_cast<int64_t>(a.getDenominator()) *
                             static_cast<int64_t>(b.getNumerator());

    int64_t tmpGCD = GCD(ABS(tmpNumerator), ABS(tmpDenominator));
    tmpNumerator = tmpNumerator / tmpGCD;
    tmpDenominator = tmpDenominator / tmpGCD;

    CheckValue(tmpNumerator);
    CheckValue(tmpDenominator);

    tmp.setNumerator(static_cast<int>(tmpNumerator));
    tmp.setDenominator(static_cast<int>(tmpDenominator));
    return tmp;
}
