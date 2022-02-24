#include "object.hpp"


bool Sphere::is_intersecting(const Line &l)
bool Sphere::is_intersecting(const Line &l) const
{
    auto dist = l.origine - center;
    return l.coeff * l.coeff * (l.dir * l.dir)
        + 2 * l.coeff * (l.dir * dist)
        + dist * dist
        - radius * radius
        == 0;
}

Vector Sphere::get_normal(const Point &p) const
{
    return p - center;
}

Texture Sphere::get_texture(const Point &p) const
{
    return texture->get_texture(p);
}
