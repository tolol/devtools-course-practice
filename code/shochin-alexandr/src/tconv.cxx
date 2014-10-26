  // Copyright 2014 Alexandr Shochin

#include "include/tconv.h"

#include <limits>
#include <string>

TemperatureConverter::TemperatureConverter(double Celsius) : Celsius_(Celsius) {
}

TemperatureConverter::~TemperatureConverter() {
}

double TemperatureConverter::GetKelvin() {
    return this->Celsius_ + 273.15;
}

double TemperatureConverter::GetFahrenheit() {
    return (9.0 / 5.0) * this->Celsius_ + 32.0;
}

double TemperatureConverter::GetNewton() {
    return (33.0 / 100.0) * this->Celsius_;
}

void TemperatureConverter::Check(int unit) {
    if (Celsius_ < -273.15) {
        throw std::string(" can not be below -273.15"); 
    }       
    if (unit > 3 || unit < 1) {
        throw std::string("take on integer values 1, 2 or 3");
    }
}

double TemperatureConverter::Convert(int unit) {
    Check(unit);
    switch (unit) {
    case 1: return GetKelvin();
    case 2: return GetFahrenheit();
    case 3: return GetNewton();
    default: return 0.0;
    }
}

