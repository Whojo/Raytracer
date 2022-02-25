#pragma once

#include "point.hpp"
#include "vector.hpp"


class Ray
{
public:
    Ray(const Vector &dir, const Point &origine)
        : dir{dir.as_unit()}, origine{origine}
        {};

public:
    const Vector dir;
    const Point origine;
};
