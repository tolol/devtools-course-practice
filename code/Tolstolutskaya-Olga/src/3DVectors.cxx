// Copyright 2014 Tolstolutskaya Olga
#include <stdio.h>
#include <math.h>
#include "include/3DVector.h"

Vector3d::Vector3d(): a(0), b(0), c(0) {}

Vector3d::Vector3d(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
Vector3d::Vector3d(const Vector3d& v) : a(v.a), b(v.b), c(v.c);
void Vector3d::operator()(double _a, double _b, double _c) {
    a = _a; b = _b; c = _c;
}

Vector3d& Vector3d::operator=(Vector3d v) {
    a = v.a;
    b = v.b;
    c = v.c;
    return *this;
}

double Vector3d::GetA() {
    return(a);
}

double Vector3d::GetB() {
    return(b);
}

double Vector3d::GetC() {
    return(c);
}

double Vector3d::Norm() {
    double LocalNorm;
    double ForSqrt = a*a+b*b+c*c;
    LocalNorm = sqrt(fabs(ForSqrt));
    return(LocalNorm);
}

void Vector3d::Normalize() {
    if ((fabs(a) > 0.00001)||(fabs(b) > 0.00001)||(fabs(c) > 0.00001)) {
        double LocalNorm = Norm();
        double inversion = 1/LocalNorm;
        a = a*inversion;
        b = b*inversion;
        c = c*inversion;
    } else {
        return;
    }
}

double Vector3d::ScalarProduct(const Vector3d &Vector) {
    double SProduct = Vector.a*a+Vector.b*b+Vector.c*c;
    return (SProduct);
}

Vector3d Vector3d::VectorProduct(const Vector3d &Vector) {
    double _a = b*Vector.c-c*Vector.b;
    double _b = -(a*Vector.c-c*Vector.a);
    double _c = a*Vector.b-b*Vector.a;
    return Vector3d(_a, _b, _c);
}
