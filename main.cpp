#include <iostream>

#include "color.hpp"
#include "engine.hpp"
#include "image.hpp"
#include "scene.hpp"
#include "texture_material.hpp"

int main(int argc, char *argv[])
{
    UniformTexture   blue_text{Texture{Color{146, 194, 182}, 1, 1, 1}};
    UniformTexture  white_text{Texture{Color{232, 236, 196}, 1, 1, 1}};
    UniformTexture orange_text{Texture{Color{236, 147, 106}, 1, 1, 1}};
    UniformTexture yellow_text{Texture{Color{213, 166,  50}, 1, 1, 1}};

    Scene scene{
        { Sphere{Point{0, 0, -10000}, 10000, white_text},
          Sphere{Point{10, 2, 1.5}, 2, blue_text},
          Sphere{Point{13, -2, 2}, 4, orange_text},
          Sphere{Point{20, 6, 3}, 8, yellow_text}},
        { PointLight{Point{6, -2, 5}, 1} },
        Camera{Point{0, 0, 5}, Vector{1, 0, -0.2}, Vector{0, 0, 1}, 90, 69, 1}
    };

    auto img = engine::generate_image(352, 240, scene);
    img.save_to_ppm("test.ppm");

    return 0;
}
