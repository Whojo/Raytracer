#pragma once

#include "point.hpp"
#include "vector.hpp"


class Light
{
public:
    const Point origin;
    const double intensity;
};

class PointLight : public Light
{
public:
    PointLight(const Point &origin, const double intensity_);
};
