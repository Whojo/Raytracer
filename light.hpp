#pragma once

#include "point.hpp"
#include "vector.hpp"


class Light
{};

class PointLight : public Light
{
public:
    PointLight(const Point &origine, const Vector &dir);

public:
    const Point origine;
    const Vector dir;
};
