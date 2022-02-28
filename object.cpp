#include "object.hpp"
#include <cmath>


Sphere::Sphere(const Point &center, const double radius, const TextureMaterial &texture_)
    : center{center}, radius{radius}
{
    texture = &texture_;
}


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

    if (d1 < epsilon and d2 < epsilon)
        return std::nullopt;

    if ((d1 >= epsilon and d1 < d2 + epsilon) or d2 < epsilon)
        return std::optional(r.origine + r.dir * d1);

    return std::optional(r.origine + r.dir * d2);
}

Vector Sphere::get_normal(const Point &p) const
{
    return (p - center).as_unit();
}

Texture Sphere::get_texture(const Point &p) const
{
    return texture->get_texture(p);
}
