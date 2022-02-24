#include "texture_material.hpp"


Texture UniformTexture::get_texture(const Point &p) const
{
    return {Color{255, 0, 0}, 1, 1, 1};
}
