// Copyright 2014 Tolstolutskaya Olga
#ifndef CODE_TOLSTOLUTSKAYA_OLGA_INCLUDE_3DVECTOR_H_
#define CODE_TOLSTOLUTSKAYA_OLGA_INCLUDE_3DVECTOR_H_
#include <stdio.h>
#include <math.h>

class Vector3d {

 public:
    Vector3d();
    Vector3d(double _a, double _b, double _c);
    Vector3d(const Vector3d& v);

    void operator()(double _a, double _b, double _c);
    Vector3d & operator=(Vector3d v);

    double GetC();
    double GetB();
    double GetA();

    double Norm();
    void Normalize();
    double ScalarProduct(const Vector3d &Vector);
    Vector3d VectorProduct(const Vector3d &Vector);

    void Print();

 private:
    double a;
    double b;
    double c;
};
#endif  // CODE_TOLSTOLUTSKAYA_OLGA_INCLUDE_3DVECTOR_H_
