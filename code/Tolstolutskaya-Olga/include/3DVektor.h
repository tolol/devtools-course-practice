// Copyright 2014 Tolstolutskaya Olga
#ifndef CODE_TOLSTOLUTSKAYA_OLGA_INCLUDE_3DVEKTOR_H_
#define CODE_TOLSTOLUTSKAYA_OLGA_INCLUDE_3DVEKTOR_H_
#include <stdio.h>
#include <math.h>

class Vector3d {
 private:
    double a;
    double b;
    double c;

 public:
    Vector3d();

    Vector3d(double _a, double _b, double _c);

    double GetC();

    double GetB();

    double GetA();

    double Norma();

    void Normalize();

    double ScalarProduct(Vector3d *Vector);

    Vector3d* VectorProduct(Vector3d *Vector);

    void Print();
};
#endif  // CODE_TOLSTOLUTSKAYA_OLGA_INCLUDE_3DVEKTOR_H_
