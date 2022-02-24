#include "point.hpp"


Point Point::operator+(const Vector &v) const
{
    return Point{x + v.x, y + v.y, z + v.z};
}

Vector Point::operator-(const Point &p) const
{
    return Vector{p.x - x, p.y - y, p.z - z};
}

std::ostream& operator<<(std::ostream &out, const Point &point)
{
    return out << "point(" << point.x << ", "
                           << point.y << ", "
                           << point.z << ")" << std::endl;
}
