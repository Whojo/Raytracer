#include "object.hpp"


Sphere::Sphere(const Point &center, const double radius)
    : center{center}, radius{radius}
{}


bool Sphere::is_intersecting(const Ray &r) const
{
    auto dist = r.origine - center;
    auto scalar_dist = r.dir * dist;
    return scalar_dist * scalar_dist
        - dist * dist
        + radius * radius
        >= 0;
}

Vector Sphere::get_normal(const Point &p) const
{
    return p - center;
}

Texture Sphere::get_texture(const Point &p) const
{
    return texture->get_texture(p);
}
