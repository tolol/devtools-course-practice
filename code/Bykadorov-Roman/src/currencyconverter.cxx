// Copyright 2014 Bykadorov Roman

#include "include/currencyconverter.h"

#include <float.h>
#include "string"

CurrencyConverter::CurrencyConverter() {}
CurrencyConverter::~CurrencyConverter() {}

void CurrencyConverter::checkRange(double value) {
    if (value < 0)
        throw std::string("The value is negative");
    if (value > DBL_MAX)
        throw std::string("The value is larger than DBL_MAX");
}
double CurrencyConverter::rubToEur(double rub) {
    return mainConverter(rub, 0);
}
double CurrencyConverter::rubToUsd(double rub) {
    return mainConverter(rub, 1);
}
double CurrencyConverter::usdToEur(double usd) {
    return mainConverter(usd, 2);
}
double CurrencyConverter::usdToRub(double usd) {
    return mainConverter(usd, 3);
}
double CurrencyConverter::eurToRub(double eur) {
    return mainConverter(eur, 4);
}
double CurrencyConverter::eurToUsd(double eur) {
    return mainConverter(eur, 5);
}
double CurrencyConverter::mainConverter(double value, int mode) {
    double _value;
    switch (mode) {
        // rubToEur(double)
        case 0:
            _value = value/_euroForRub;
        break;
        // rubToUsd(double)
        case 1:
            _value = value/_usdForRub;
        break;
        // usdToEur(double)
        case 2:
            _value = value*(_usdForRub/_euroForRub);
        break;
        // usdToRub(double)
        case 3:
            _value = value*_usdForRub;
        break;
        // eurToRub(double)
        case 4:
            _value = value*_euroForRub;
        break;
        // eurToUsd(double)
        case 5:
            _value = value*(_euroForRub/_usdForRub);
        break;
    }
    checkRange(_value);
    return _value;
}

