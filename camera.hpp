#pragma once

#include "point.hpp"
#include "vector.hpp"


class Camera
{

public:
    const Point center;
    const Vector direction;
    const Vector up;
    const double alpha;
    const double beta;
    const double z_min;
};
