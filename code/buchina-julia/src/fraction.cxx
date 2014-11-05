// Copyright 2014 Julia Buchina

#include "include/fraction.h"

Fraction::Fraction(): numerator(0), denominator(1) {}
Fraction::~Fraction() {}

Fraction::Fraction(int _numerator, int _denominator) {
    if (_denominator != 0) {
        numerator = _numerator;
        denominator = _denominator;
    } else {
        return;
    }
}

Fraction::Fraction(const Fraction& fraction): numerator(fraction.getNumerator()),
                                              denominator(fraction.getDenominator()) {}
int Fraction::getNumerator() {
    return numerator;
}

int Fraction::getDenominator() {
    return denominator;
}

Fraction& Fraction::operator=(const Fraction& fraction) {
    numerator = fraction.getNumerator();
    denominator = fraction.getDenominator();
    return *this;
}

Fraction& Fraction::operator+(const Fraction& a, const Fraction& b) {}
