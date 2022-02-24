#pragma once

#include "point.hpp"
#include "color.hpp"


struct Texture
{
    const Color color;
    const double specular_pickyness;
    const double specular_lightness;
    const double specular_coefficient;
};

 class TextureMaterial
 {
public:
     virtual Texture get_texture(const Point &p) const = 0;
 };

class UniformTexture : TextureMaterial
{
     Texture get_texture(const Point &p) const override;
};
