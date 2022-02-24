#pragma once

#include "point.hpp"
#include "vector.hpp"


class Light
{};

class PointLight : Light
{
public:
    const Point origine;
    const Vector dir;
};
