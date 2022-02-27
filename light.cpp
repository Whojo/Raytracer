#include "light.hpp"


PointLight::PointLight(const Point &origin, const double intensity)
    : Light{origin, intensity}
{}
