#include "vector.hpp"


double Vector::operator*(const Vector &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

Vector Vector::operator*(const double &a) const
{
    return Vector{x * a, y * a, z * a};
}

Vector Vector::operator-(const Vector &v) const
{
    return Vector{x - v.x, y - v.y, z - v.z};
}

std::ostream& operator<<(std::ostream &out , Vector &vect)
{
    return out << "Vect(" << vect.x << ", "
                          << vect.y << ", "
                          << vect.z << ")" << std::endl;
}
