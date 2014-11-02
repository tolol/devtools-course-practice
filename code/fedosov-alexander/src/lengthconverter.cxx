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
        length = 0.0;
    }
return length;
}

double LengthConverter::convertInchesToMeters(double length) {
    length*=0.0254; return(checkLength(length));
}
double LengthConverter::convertFootsToMeters(double length) {
    length*=0.3048; return(checkLength(length));
}
double LengthConverter::convertYardsToMeters(double length) {
    length*=0.9144; return(checkLength(length));
}
double LengthConverter::convertMilesToMeters(double length) {
    length*=1609.344; return(checkLength(length));
}

double LengthConverter::convertMetersToInches(double length) {
    length*=39.3701; return(checkLength(length));
}
double LengthConverter::convertFootsToInches(double length) {
    length*=12.0; return(checkLength(length));
}
double LengthConverter::convertYardsToInches(double length) {
    length*=36.0; return(checkLength(length));
}
double LengthConverter::convertMilesToInches(double length) {
    length*=63360.0; return(checkLength(length));
}
double LengthConverter::convertMetersToFoots(double length) {
    length*=3.2808; return(checkLength(length));
}
double LengthConverter::convertInchesToFoots(double length) {
    length*=0.0833; return(checkLength(length));
}
double LengthConverter::convertYardsToFoots(double length) {
    length*=3.0; return(checkLength(length));
}
double LengthConverter::convertMilesToFoots(double length) {
    length*=5280.0; return(checkLength(length));
}

double LengthConverter::convertMetersToYards(double length) {
    length*=1.0936; return(checkLength(length));
}
double LengthConverter::convertInchesToYards(double length) {
    length*=0.0278; return(checkLength(length));
}
double LengthConverter::convertFootsToYards(double length) {
    length*=0.3333333; return(checkLength(length));
}
double LengthConverter::convertMilesToYards(double length) {
    length*=1760.0; return(checkLength(length));
}

double LengthConverter::convertMetersToMiles(double length) {
    length*=0.0006214; return(checkLength(length));
}
double LengthConverter::convertInchesToMiles(double length) {
    length*=0.000016; return(checkLength(length));
}
double LengthConverter::convertFootsToMiles(double length) {
    length*=0.0001894; return(checkLength(length));
}
double LengthConverter::convertYardsToMiles(double length) {
    length*=0.0005682; return(checkLength(length));
}
