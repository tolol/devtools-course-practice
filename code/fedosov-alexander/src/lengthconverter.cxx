// Copyright 2014 Fedosov Alexander

#include <float.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <set>
#include "Includes/lengthconverter.hpp"
Length::Length():type_(Type::TYPE_METER), length_(0.0) {}
Length::Length(Type type, double length):type_(type), length_(length) {
    length_ = checkLength(length);
    if (checkType(type) == Type::TYPE_WRONG) {
        throw std::string("Unknown type");} else {
    type_ = type;
}
}
Length::Type Length::getType() {return type_;}
double Length::getLength() {return length_;}
void Length::setLength(double length) {
    length_ = Length::checkLength(length);
}
void Length::setType(Type type) {
    Length* tmp;
    type = checkType(type);
    tmp = this->convert(type);
    if (tmp != NULL) {
        type_ = type;
        this->setLength(tmp->getLength());
    } else { return;}
}
double Length::checkLength(double length) {
if (length < 0.0000001) {
        length = 0.0;
    }
return length;
}
Length* Length::convert(Type type) {
    double length;
    length = this->getLength();
    double *lngth = &length;
    Length* converted;
    type = checkType(type);
    switch (type) {
        case Type::TYPE_METER: {this->convertToMeters(lngth); length = *lngth;
            converted = new Length(type, length); return converted;}
        case Type::TYPE_MILE: {this->convertToMiles(lngth); length = *lngth;
            converted = new Length(type, length); return converted;}
        case Type::TYPE_YARD: {this->convertToYards(lngth); length = *lngth;
            converted = new Length(type, length); return converted;}
        case Type::TYPE_FOOT: {this->convertToFoots(lngth); length = *lngth;
            converted = new Length(type, length); return converted;}
        case Type::TYPE_INCH: {this->convertToInches(lngth); length = *lngth;
            converted = new Length(type, length); return converted;}
        default: {return NULL;}
    }
}
void Length::convertToMeters(double* length) {
Type myType;
double lngth = *length;
myType = this->getType();
    if (myType == Type::TYPE_METER) {lngth = checkLength(lngth);
            *length = lngth; return;}
    if (myType == Type::TYPE_MILE) {lngth*=1609.344;
            lngth = checkLength(lngth); *length = lngth; return;}
    if (myType == Type::TYPE_YARD) {lngth*=0.9144;
            lngth = checkLength(lngth); *length = lngth; return;}
    if (myType == Type::TYPE_FOOT) {lngth*=0.3048;
            lngth = checkLength(lngth); *length = lngth; return;}
    if (myType == Length::Type::TYPE_INCH) {lngth*=0.0254;
            lngth = checkLength(lngth); *length = lngth; return;}
}
void Length::convertToInches(double* length) {
Type myType;
double lngth = *length;
myType = this->getType();
if (myType == Type::TYPE_METER) {lngth*=39.3701;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_MILE) {lngth*=63360.0;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_YARD) {lngth*=36.0;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_FOOT) {lngth*=12.0;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_INCH) {lngth = checkLength(lngth);
            *length = lngth; return;}
}
void Length::convertToFoots(double* length) {
Type myType;
double lngth = *length;
myType = this->getType();
if (myType == Type::TYPE_METER) {lngth*=3.2808;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_MILE) {lngth*=5280.0;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_YARD) {lngth*=3.0;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_FOOT) {lngth = checkLength(lngth);
            *length = lngth; return;}
if (myType == Type::TYPE_INCH) {lngth*=0.0833;
            lngth = checkLength(lngth); *length = lngth; return;}
}
void Length::convertToYards(double* length) {
Type myType;
double lngth = *length;
myType = this->getType();
if (myType == Type::TYPE_METER) {lngth*=1.0936;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_MILE) {lngth*=1760.0;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_YARD) {lngth = checkLength(lngth);
            *length = lngth; return;}
if (myType == Type::TYPE_FOOT) {lngth*=0.3333333;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_INCH) {lngth*=0.0278;
            lngth = checkLength(lngth); *length = lngth; return;}
}
void Length::convertToMiles(double* length) {
Type myType;
double lngth = *length;
myType = this->getType();
if (myType == Type::TYPE_METER) {lngth*=0.0006214;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_MILE) {lngth = checkLength(lngth);
            *length = lngth; return;}
if (myType == Type::TYPE_YARD) {lngth*=0.0005682;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_FOOT) {lngth*=0.0001894;
            lngth = checkLength(lngth); *length = lngth; return;}
if (myType == Type::TYPE_INCH) {lngth*=0.000016;
            lngth = checkLength(lngth); *length = lngth; return;}
}
Length::Type Length::checkType(Type type) {
    if ((type <= Type::TYPE_MILE)&&(type > Type::TYPE_WRONG)) {
        return type;
    } else {return Type::TYPE_WRONG;}
}
