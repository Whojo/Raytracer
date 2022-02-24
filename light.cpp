#include "light.hpp"


PointLight::PointLight(const Point &origine, const Vector &dir)
    : origine{origine}, dir{dir}
{}
