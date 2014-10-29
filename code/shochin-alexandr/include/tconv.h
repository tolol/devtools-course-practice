// Copyright 2014 Shochin Alexandr

#ifndef CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_
#define CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_

class TemperatureConverter {
 private:
     double celsius_;
 public:
     explicit TemperatureConverter(double celsius);
     ~TemperatureConverter();
     double Convert(int unit);
 protected:
     void Check();
     double GetKelvin();
     double GetFahrenheit();
     double GetNewton();
};

#endif  // CODE_SHOCHIN_ALEXANDR_INCLUDE_TCONV_H_
