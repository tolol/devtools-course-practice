// Copyright 2014 Shochin Alexandr

#ifndef CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_
#define CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_

class TemperatureConverter {
 private:
     double сelsius_;
 public:
     explicit TemperatureConverter(double сelsius);
     ~TemperatureConverter();
     double Convert(int unit);
 protected:
     void Check();
     double GetKelvin();
     double GetFahrenheit();
     double GetNewton();
};

#endif  // CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_
