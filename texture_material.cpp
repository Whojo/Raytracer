#include "texture_material.hpp"


UniformTexture::UniformTexture(const Texture &texture_)
    : texture{texture_}
{}

Texture UniformTexture::get_texture(const Point &p) const
{
    return texture;
}
