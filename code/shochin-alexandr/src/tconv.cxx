  // Copyright 2014 Alexandr Shochin

#include "include/tconv.h"

#include <limits>
#include <string>

TemperatureConverter::TemperatureConverter(double celsius) : celsius_(celsius) {
}

TemperatureConverter::~TemperatureConverter() {
}

double TemperatureConverter::GetKelvin() {
    return this->celsius_ + 273.15;
}

double TemperatureConverter::GetFahrenheit() {
    return (9.0 / 5.0) * this->celsius_ + 32.0;
}

double TemperatureConverter::GetNewton() {
    return (33.0 / 100.0) * this->celsius_;
}

void TemperatureConverter::Check() {
    if (celsius_ < -273.15) {
        throw std::string(" can not be below -273.15");
    }
}

double TemperatureConverter::Convert(int unit) {
    Check();
    switch (unit) {
    case 1: return GetKelvin();
    case 2: return GetFahrenheit();
    case 3: return GetNewton();
    default: throw std::string("unit should be in the range from 1 to 3");
    }
}

