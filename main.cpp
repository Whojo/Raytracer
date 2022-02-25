#include "color.hpp"
#include "engine.hpp"
#include "image.hpp"
#include "scene.hpp"
#include "texture_material.hpp"

int main(int argc, char *argv[])
{
    UniformTexture test{Texture{Color{0, 255, 0}, 1, 1, 1}};
    Scene scene{
        { Sphere{Point{10, 1, 0}, 2, test} },
        { PointLight{Point{0, 0, 0}, Vector{1, 0, 0}} },
        Camera{Point{0, 0, 0}, Vector{1, 0, 0}, Vector{0, 0, 1}, 90, 69, 1}
    };

    auto img = engine::generate_image(352, 240, scene);
    img.save_to_ppm("test.ppm");

    return 0;
}
