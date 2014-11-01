// Copyright 2014 Fedosov Alexander

#ifndef CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
#define CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
extern const int64_t TYPE_METER;
extern const int64_t TYPE_MILE;
extern const int64_t TYPE_YARD;
extern const int64_t TYPE_FOOT;
extern const int64_t TYPE_INCH;
class Length {
 public:
Length();
static Length* create(int64_t type, double length);
Length* convert(int64_t type);
void setType(int64_t type);
int64_t getType();
double getLength();
void setLength(double length);
 private:
int64_t type_;
double length_;
Length(int64_t type, double length);
void convert(int64_t type, double* length);
static double checkLength(double length);
};
#endif
