// Copyright 2014 Fedosov Alexander

#ifndef CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
#define CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
class Length {
 public:
enum class Type {TYPE_WRONG, TYPE_METER,
    TYPE_INCH, TYPE_FOOT, TYPE_YARD, TYPE_MILE};
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
