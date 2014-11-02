// Copyright 2014 Fedosov Alexander

#ifndef CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
#define CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
class Length {
 public:
enum {
TYPE_WRONG = -1,
TYPE_METER = 1,
TYPE_INCH = 2,
TYPE_FOOT = 3,
TYPE_YARD = 4,
TYPE_MILE = 5};
Length();
Length(int64_t type, double length);
Length* convert(int64_t type);
void setType(int64_t type);
int64_t getType();
double getLength();
void setLength(double length);

 private:
int64_t type_;
double length_;
void convertToMeters(double* length);
void convertToInches(double* length);
void convertToFoots(double* length);
void convertToYards(double* length);
void convertToMiles(double* length);
static int64_t checkType(int64_t type);
static double checkLength(double length);
};
#endif
