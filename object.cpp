#include "object.hpp"
#include <cmath>


Sphere::Sphere(const Point &center, const double radius)
    : center{center}, radius{radius}
{}


std::optional<Point> Sphere::get_intersection(const Ray &r) const
{
    auto dist = r.origine - center;
    auto scalar_dist = r.dir * dist;
    auto delta = scalar_dist * scalar_dist - dist * dist + radius * radius;

    if (delta < 0)
        return std::nullopt;

    if (delta == 0)
        return std::optional(r.origine + r.dir * -scalar_dist);

    auto sqrt_delta = sqrt(delta);
    auto d1 = -scalar_dist + sqrt_delta;
    auto d2 = -scalar_dist - sqrt_delta;

    if (d1 < 0 and d2 < 0)
        return std::nullopt;

    if ((d1 >= 0 and d1 < d2) or d2 < 0)
        return std::optional(r.origine + r.dir * d1);

    return std::optional(r.origine + r.dir * d2);
}

Vector Sphere::get_normal(const Point &p) const
{
    return p - center;
}

Texture Sphere::get_texture(const Point &p) const
{
    return texture->get_texture(p);
}
