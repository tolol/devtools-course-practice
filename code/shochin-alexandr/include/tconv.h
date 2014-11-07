// Copyright 2014 Shochin Alexandr

#ifndef CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_
#define CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_

enum Unit {Celsius, Kelvin, Fahrenheit, Newton};

#pragma pack(push, 1)
struct Temperature {
    double value;
    Unit unit;
};
#pragma pack(pop)

class TemperatureConvertor {
 public:
    TemperatureConvertor();
    ~TemperatureConvertor();
    double Convert(Temperature temp, Unit unit);

 private:
    static double auxiliaryArrayOne[4];
    static double auxiliaryArrayTwo[4];
    int Check(Temperature temp);
    double ConvertFromCelsius(Temperature temp, Unit unit);
    double ConvertToCelsius(Temperature temp);
};

#endif  // CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_
