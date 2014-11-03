// Copyright 2014 Fedosov Alexander

#ifndef CODE_FEDOSOV_ALEXANDER_INCLUDE_LENGTHCONVERTER_HPP_
#define CODE_FEDOSOV_ALEXANDER_INCLUDE_LENGTHCONVERTER_HPP_
class LengthConverter {
 public:
    enum {
        TYPE_METER = 1,
        TYPE_INCH = 2,
        TYPE_FOOT = 3,
        TYPE_YARD = 4,
        TYPE_MILE = 5
    };
    LengthConverter();
    ~LengthConverter();
    double convertToMeters(int64_t type, double length);
    double convertMetersTo(int64_t type, double length);
    double convert(int64_t from, double length, int64_t to);

 private:
    static double checkLength(double length);
};
#endif
