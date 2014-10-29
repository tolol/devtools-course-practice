// Copyright 2014 Sirotin Nikita

#include "include/volumefigures.h"

#include <stdint.h>
#include <math.h>
#include <float.h>
#include <string>

Volume::Volume() {}
Volume::~Volume() {}

void CheckRange(double result);
void CheckRange(double result) {
    if (result > DBL_MAX)
        throw std::string("The result is larger than DBL_MAX");
    else if (result < -DBL_MAX)
        throw std::string("The result is less than -DBL_MAX");
    if (result == 0.)
      throw std::string("There are zero variables");
}

double Volume::Cube(double side) {
  double vol = pow(side, 3);
  CheckRange(vol);

  return vol;
}

double Volume::Sphere(double radius) {
  double vol = 4 * M_PI * pow(radius, 3) / 3;
  CheckRange(vol);

  return vol;
}

double Volume::Pyramid(double height, double area) {
  double vol = area * height / 3;
  CheckRange(vol);

  return vol;
}

double Volume::Cylinder(double height, double radius) {
  double area = radius * radius * M_PI;
  CheckRange(area);
  double vol = area * height;
  CheckRange(vol);

  return vol;
}
