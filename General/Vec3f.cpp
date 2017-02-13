#include "Vec3f.h"

Vec3f::Vec3f() {
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Vec3f::Vec3f(double ix, double iy, double iz)
{
    this->x = ix;
    this->y = iy;
    this->z = iz;
}
