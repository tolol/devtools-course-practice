//  Copyright 2014 Shochin Alexandr


#include "include/tconv.h"

#include <limits>
#include <string>

TemperatureConverter::TemperatureConverter(double Celsius) {
     this->Celsius_ = Celsius;
}

TemperatureConverter::~TemperatureConverter() {
};

double TemperatureConverter::GetKelvin() {
    return this->Celsius_ + 273.15;
}

double TemperatureConverter::GetFahrenheit() {
    return (9.0 / 5.0) * this->Celsius_ + 32.0;
}

double TemperatureConverter::GetNewton() {
    return (33.0 / 100.0) * this->Celsius_;
}

int TemperatureConverter::Check() {
    int RetCode = 0;

    if (Celsius_ >= -273.15) {
        RetCode = 1;
    }
    return RetCode;
}

double TemperatureConverter::Convert(int unit) {
    int RetCode = Check();

    if (RetCode == 1) {
        if (unit >= 1 && unit <= 3) {
            switch (unit) {
            case 1: return GetKelvin();
            case 2: return GetFahrenheit();
            case 3: return GetNewton();
            }
        } else {
            throw std::string("take on integer values 1, 2 or 3");
        }
    } else {
        throw std::string(" can not be below -273.15");
    }
    return NULL;
}
