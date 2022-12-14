#pragma once

#include "point.hpp"
#include "color.hpp"


struct Texture
{
    const Color color;
    const double specular_pickyness;
    const double specular_lightness;
    const double diffusion_lightness;
};

 class TextureMaterial
 {
public:
     virtual Texture get_texture(const Point &p) const = 0;
 };

class UniformTexture : public TextureMaterial
{
public:
    UniformTexture(const Texture &texture_);
    Texture get_texture(const Point &p) const override;

public:
    const Texture texture;
};
