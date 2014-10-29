// Copyright 2014 Sirotin Nikita

#ifndef CODE_SIROTIN_NIKITA_LABA2_INCLUDE_VOLUMEFIGURES_H_
#define CODE_SIROTIN_NIKITA_LABA2_INCLUDE_VOLUMEFIGURES_H_

class Volume {
 public:
  Volume();
  ~Volume();

  double Cube(double side);
  double Sphere(double radius);
  double Pyramid(double height, double area);
  double Cylinder(double height, double radius);
};

#endif  // CODE_SIROTIN_NIKITA_LABA2_INCLUDE_VOLUMEFIGURES_H_
