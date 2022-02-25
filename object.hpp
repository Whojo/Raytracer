#pragma once

#include <optional>

#include "ray.hpp"
#include "vector.hpp"
#include "texture_material.hpp"


class Object
{
public:
    virtual std::optional<Point> get_intersection(const Ray &r) const = 0;
    virtual Vector get_normal(const Point &p) const = 0;
    virtual Texture get_texture(const Point &p) const = 0;

public:
    TextureMaterial *texture;
};


class Sphere : public Object
{
public:
    Sphere(const Point &center, const double radius);

    std::optional<Point> get_intersection(const Ray &r) const override;
    Vector get_normal(const Point &p) const override;
    Texture get_texture(const Point &p) const override;

public:
    const Point center;
    const double radius;
};
