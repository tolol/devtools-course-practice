// Copyright 2014 Sirotin Nikita

#ifndef CODE_SIROTIN_NIKITA_LABA2_INCLUDE_VOLUMEFIGURES_H_
#define CODE_SIROTIN_NIKITA_LABA2_INCLUDE_VOLUMEFIGURES_H_

class Volume {
 public:
  Volume();
  ~Volume();

  double cube(const double side);
  double sphere(const double radius);
  double pyramid(const double height, const double area);
  double cylinder(const double height, const double radius);
};

#endif  // CODE_SIROTIN_NIKITA_LABA2_INCLUDE_VOLUMEFIGURES_H_
