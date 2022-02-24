#pragma once

#include "line.hpp"
#include "vector.hpp"
#include "texture_material.hpp"


class Object
{
public:
    virtual bool is_intersecting(const Line &l) = 0;
    virtual Vector get_normal(const Point &p) = 0;
    virtual Texture get_texture(const Point &p) = 0;

public:
    TextureMaterial *texture;
};


class Sphere : Object
{
public:
    bool is_intersecting(const Line &l) override;
    Vector get_normal(const Point &p) override;
    Texture get_texture(const Point &p) override;

public:
    const Point center;
    const double radius;
};
