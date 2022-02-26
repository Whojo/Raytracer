#include "color.hpp"
#include "engine.hpp"
#include "image.hpp"
#include "scene.hpp"
#include "texture_material.hpp"

int main(int argc, char *argv[])
{
    UniformTexture  green_text{Texture{Color{119, 223, 143}, 1, 1, 1}};
    UniformTexture orange_text{Texture{Color{236, 112,   0}, 1, 1, 1}};
    Scene scene{
        { Sphere{Point{10, 1, 0}, 2, green_text}, Sphere{Point{13, -2, 2}, 4, orange_text}},
        { PointLight{Point{0, 0, 0}, Vector{1, 0, 0}} },
        Camera{Point{0, 0, 0}, Vector{1, 0, 0}, Vector{0, 0, 1}, 90, 69, 1}
    };

    auto img = engine::generate_image(352, 240, scene);
    img.save_to_ppm("test.ppm");

    return 0;
}
