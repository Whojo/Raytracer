#include "vector.hpp"

#include <cmath>
#include <stdexcept>


double Vector::operator*(const Vector &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

Vector Vector::operator*(const double &a) const
{
    return Vector{x * a, y * a, z * a};
}

Vector Vector::operator/(const double &a) const
{
    return Vector{x / a, y / a, z / a};
}

Vector Vector::operator-(const Vector &v) const
{
    return Vector{x - v.x, y - v.y, z - v.z};
}

Vector Vector::operator-() const
{
    return Vector{-x, -y, -z};
}

bool Vector::operator==(const Vector &v) const
{
    return x == v.x and y == v.y and z == v.z;
}

bool are_colinear(const Vector &lhs, const Vector &rhs)
{
    return cross_product(lhs, rhs) == Vector{0, 0, 0};
}

Vector cross_product(const Vector &lhs, const Vector &rhs)
{
    return Vector{ lhs.y * rhs.z - lhs.z * rhs.y,
                   lhs.z * rhs.x - lhs.x * rhs.z,
                   lhs.x * rhs.y - lhs.y * rhs.x };
}

double Vector::amplitude() const
{
    return sqrt(x * x + y * y + z * z);
}

Vector Vector::as_unit() const
{
    if (x == 0 and y == 0 and z == 0)
        throw std::invalid_argument("Cannot compute unitary vector from a nul vector");

    auto amplitude = Vector::amplitude();
    return Vector{x / amplitude, y / amplitude, z / amplitude};
}

std::ostream& operator<<(std::ostream &out , Vector &vect)
{
    return out << "Vect(" << vect.x << ", "
                          << vect.y << ", "
                          << vect.z << ")";
}
