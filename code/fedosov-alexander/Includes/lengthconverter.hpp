// Copyright 2014 Fedosov Alexander

#ifndef CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
#define CODE_FEDOSOV_ALEXANDER_INCLUDES_LENGTHCONVERTER_HPP_
extern const int TYPE_METER;
extern const int TYPE_MILE;
extern const int TYPE_YARD;
extern const int TYPE_FOOT;
extern const int TYPE_INCH;
class Length {
 public:
int useless_;
Length();
~Length();
static Length* create(int type, double length);
Length* convert(int type);
void setType(int type);
int getType();
double getLength();
void setLength(double length);
 private:
double length_;
int type_;
Length(int type, double length);
void convert(int type, double* length);
static double checkLength(double length);
};
#endif
