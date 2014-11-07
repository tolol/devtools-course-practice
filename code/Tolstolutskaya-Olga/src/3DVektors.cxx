// Copyright 2014 Tolstolutskaya Olga
#include <stdio.h>
#include <math.h>
#include "include/3DVektor.h"

Vector3d::Vector3d(): a(0), b(0), c(0) {}

Vector3d::Vector3d(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}

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

double Vector3d::ScalarProduct(Vector3d *Vector) {
    double SProduct = Vector->a*a+Vector->b*b+Vector->c*c;
    return (SProduct);
}

Vector3d* Vector3d::VectorProduct(Vector3d *Vector) {
    Vector3d *VProduct = new Vector3d();
    VProduct->a = b*Vector->c-c*Vector->b;
    VProduct->b = -(a*Vector->c-c*Vector->a);
    VProduct->c = a*Vector->b-b*Vector->a;
    return(VProduct);
}
