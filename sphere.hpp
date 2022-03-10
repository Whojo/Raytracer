#pragma once

#include "object.hpp"

class Sphere : public Object
{
public:
    Sphere(const Point &center, const double radius, const TextureMaterial &texture_);

    std::optional<Point> get_intersection(const Ray &r) const override;
    Vector get_normal(const Point &p) const override;
    Texture get_texture(const Point &p) const override;

public:
    const Point center;
    const double radius;
};
