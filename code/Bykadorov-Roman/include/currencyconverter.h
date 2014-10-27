// Copyright 2014 Bykadorov Roman

#ifndef CODE_BYKADOROV_ROMAN_INCLUDE_CURRENCYCONVERTER_H_
#define CODE_BYKADOROV_ROMAN_INCLUDE_CURRENCYCONVERTER_H_

class CurrencyConverter {
 public:
    CurrencyConverter();
    ~CurrencyConverter();
    double rubToEur(double rub);
    double rubToUsd(double rub);
    double eurToUsd(double eur);
    double eurToRub(double eur);
    double usdToRub(double usd);
    double usdToEur(double usd);
    double mainConverter(double value, int mode);
 private:
    void checkRange(double value);
};
#endif  // CODE_BYKADOROV_ROMAN_INCLUDE_CURRENCYCONVERTER_H_
