#include "color.hpp"

#include "image.hpp"
#include "scene.hpp"

int main(int argc, char *argv[])
{
    Scene scene{
        { Sphere{Point{10, 0, 0}, 3} },
        { PointLight{Point{0, 0, 0}, Vector{1, 0, 0}} },
        Camera{Point{0, 0, 0}, Vector{1, 0, 0}, Vector{0, 0, 1}, 30, 30, 1}
    };

    return 0;
}
