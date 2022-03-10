#include "triangle.hpp"
#include <cmath>

#include <iostream>


Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3,
                   const TextureMaterial &texture_)
    : points{{p1, p2, p3}}
{
    texture = &texture_;
}

// TODO: Improve speed with an other algorithm
std::optional<Point> Triangle::get_intersection(const Ray &r) const
{
    auto v1 = points[1] - points[0];
    auto v2 = points[2] - points[0];
    auto n = cross_product(v1, v2);

    auto det = -(r.dir * n);
    if (det < epsilon && det > -epsilon)
        return std::nullopt;

    auto dist = r.origine - points[0];
    auto DAO = cross_product(dist, r.dir);

    auto u =   v2 * DAO  / det;
    auto v = -(v1 * DAO) / det;
    auto t =   dist * n  / det;

    if (t < epsilon || u < epsilon || v < epsilon || (u + v) > 1)
        return std::nullopt;

    return r.origine + r.dir * t;
}

Vector Triangle::get_normal(const Point &p) const
{
    auto v1 = points[0] - points[1];
    auto v2 = points[0] - points[2];

    return cross_product(v1, v2).as_unit();
}

Vector Triangle::get_facing_normal(const Point &p, const Ray &ray)
{
    auto n = get_normal(p);

    if (n * ray.dir < 0)
        return -n;

    return n;
}

Texture Triangle::get_texture(const Point &p) const
{
    return texture->get_texture(p);
}
