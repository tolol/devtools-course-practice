
// Copyright 2014 Fedosov Alexander

#include <float.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <set>
#include "include/lengthconverter.hpp"

LengthConverter::LengthConverter() {}
LengthConverter::~LengthConverter() {}

double LengthConverter::checkLength(double length) {
if (length < 0.0000001) {
        throw std::string("Length can't be below zero!");
    }
return length;
}

double LengthConverter::convertToMeters(Type type, double length) {
     switch (type) {
        case LengthConverter::TYPE_METER: {return checkLength(length);}
        case LengthConverter::TYPE_INCH: {
            length*=0.0254; return(checkLength(length));}
        case LengthConverter::TYPE_FOOT: {
            length*=0.3048; return(checkLength(length));}
        case LengthConverter::TYPE_YARD: {
            length*=0.9144; return(checkLength(length));}
        case LengthConverter::TYPE_MILE: {
            length*=1609.344; return(checkLength(length));}
    }
    throw std::string("Unknown type");
}
double LengthConverter::convertMetersTo(Type type, double length) {
     switch (type) {
        case LengthConverter::TYPE_METER: {return checkLength(length);}
        case LengthConverter::TYPE_INCH: {
            length*=39.37007874; return(checkLength(length));}
        case LengthConverter::TYPE_FOOT: {
            length*=3.28083989; return(checkLength(length));}
        case LengthConverter::TYPE_YARD: {
            length*=1.09361329; return(checkLength(length));}
        case LengthConverter::TYPE_MILE: {
            length*=0.00062137; return(checkLength(length));}
    }
    throw std::string("Unknown type");
}
double LengthConverter::convert(Type from, double length, Type to) {
    return (convertMetersTo(to, (convertToMeters(from, length))));
}
