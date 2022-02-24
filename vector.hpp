#pragma once

#include <ostream>


class Vector
{
public:
    double operator*(const Vector &v) const;
    Vector operator*(const double &a) const;
    Vector operator-(const Vector &v) const;

public:
    double x;
    double y;
    double z;
};

std::ostream& operator<<(std::ostream &out , Vector &vect);
