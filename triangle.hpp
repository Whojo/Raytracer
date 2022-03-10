#include "object.hpp"

#include <array>


class Triangle : public Object
{
public:
    Triangle(const Point &p1, const Point &p2, const Point &p3,
             const TextureMaterial &texture_);

    std::optional<Point> get_intersection(const Ray &r) const override;
    Vector get_normal(const Point &p) const override;
    Vector get_facing_normal(const Point &p, const Ray &ray);
    Texture get_texture(const Point &p) const override;

public:
    const std::array<Point, 3> points;
};
