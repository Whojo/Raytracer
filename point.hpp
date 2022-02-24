#pragma once

#include <ostream>

#include "vector.hpp"


class Point
{
public:
    Point operator+(const Vector &v) const;
    Vector operator-(const Point &p) const;

public:
    double x;
    double y;
    double z;
};

std::ostream& operator<<(std::ostream &out, const Point &point);
