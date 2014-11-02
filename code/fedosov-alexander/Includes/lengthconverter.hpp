// Copyright 2014 Fedosov Alexander

#ifndef CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
#define CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
class Length {
 public:
enum class Type : int64_t {TYPE_WRONG = -1, TYPE_METER = 1,
    TYPE_INCH = 2, TYPE_FOOT = 3, TYPE_YARD = 4, TYPE_MILE = 5};
Length();
Length(Type type, double length);
Length* convert(Type type);
void setType(Type type);
Type getType();
double getLength();
void setLength(double length);
 private:
Type type_;
double length_;
void convertToMeters(double* length);
void convertToInches(double* length);
void convertToFoots(double* length);
void convertToYards(double* length);
void convertToMiles(double* length);
static Type checkType(Type type);
static double checkLength(double length);
};
#endif
