// Copyright 2014 Sirotin Nikita

#include "include/volumefigures.h"

#include <stdint.h>
#include <math.h>
#include <float.h>
#include <string>

Volume::Volume() {}
Volume::~Volume() {}

void CheckValue(double value);
void CheckRange(double result);

void CheckValue(double value) {
  if (value < 0.)
    throw std::string("The variable can not be less than zero");
}

void CheckRange(double result) {
    if (DBL_MAX - result < 1e-10)
        throw std::string("The result is larger than DBL_MAX");
    if (result < 1e-10)
      throw std::string("There are zero variables");
}

double Volume::cube(const double side) {
  CheckValue(side);

  double vol = pow(side, 3);
  CheckRange(vol);

  return vol;
}

double Volume::sphere(const double radius) {
  CheckValue(radius);

  double vol = 4. * M_PI * pow(radius, 3) / 3.;
  CheckRange(vol);

  return vol;
}

double Volume::pyramid(const double height, const double area) {
  CheckValue(height);
  CheckValue(area);

  double vol = area * height / 3.;
  CheckRange(vol);

  return vol;
}

double Volume::cylinder(const double height, const double radius) {
  CheckValue(height);
  CheckValue(radius);

  double area = radius * radius * M_PI;
  CheckRange(area);
  double vol = area * height;
  CheckRange(vol);

  return vol;
}
