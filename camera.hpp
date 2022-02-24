#pragma once

#include "point.hpp"
#include "vector.hpp"


class Camera
{

public:
    const Point center;
    const Vector direction;
    const Vector up;
    const double alpha; // Angle in degree
    const double beta; // Angle in degree
    const double z_min;
};
