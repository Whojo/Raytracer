#pragma once

#include <ostream>


class Vector
{
public:
    double operator*(const Vector &v) const;
    Vector operator*(const double &a) const;
    Vector operator/(const double &a) const;
    Vector operator-(const Vector &v) const;
    Vector operator-() const;
    bool   operator==(const Vector &v) const;
    double amplitude() const;
    Vector as_unit() const;

public:
    double x;
    double y;
    double z;
};

bool are_colinear(const Vector &lhs, const Vector &rhs);
Vector cross_product(const Vector &lhs, const Vector &rhs);
std::ostream& operator<<(std::ostream &out, const Vector &vect);
