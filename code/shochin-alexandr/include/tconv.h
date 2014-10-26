// Copyright 2014 Shochin Alexandr

#ifndef CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_
#define CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_

class TemperatureConverter {
 private:
     double Celsius_;
 public:
     TemperatureConverter(double Celsius);
     ~TemperatureConverter();
     double Convert(int unit);
 protected:
     int Check();
     double GetKelvin();
     double GetFahrenheit();
     double GetNewton();
};

#endif  // CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_
