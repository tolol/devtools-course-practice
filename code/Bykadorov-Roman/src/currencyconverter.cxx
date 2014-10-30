// Copyright 2014 Bykadorov Roman

#include "include/currencyconverter.h"

#include <float.h>
#include "string"

CurrencyConverter::CurrencyConverter() {}
CurrencyConverter::~CurrencyConverter() {}

const double euroForRub = 53.5948527;
const double usdForRub = 42.2600685;
const double euroForUsd = euroForRub/usdForRub;
const double usdForEuro = usdForRub/euroForRub;

void CurrencyConverter::checkRange(double value) {
    if (value < 0)
        throw std::string("The value is negative");
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
    double _value = 0;
    switch (mode) {
        // rubToEur(double)
        case 0:
            _value = value/euroForRub;
        break;
        // rubToUsd(double)
        case 1:
            _value = value/usdForRub;
        break;
        // usdToEur(double)
        case 2:
            _value = value*(usdForEuro);
        break;
        // usdToRub(double)
        case 3:
            _value = value*usdForRub;
        break;
        // eurToRub(double)
        case 4:
            _value = value*euroForRub;
        break;
        // eurToUsd(double)
        case 5:
            _value = value*(euroForUsd);
        break;
    }
    checkRange(_value);
    return _value;
}

