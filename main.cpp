#include "color.hpp"

#include "image.hpp"
#include "color.hpp"

int main(int argc, char *argv[])
{
    Image img{4, 4, {
        { Color{255, 0, 0}, Color{255, 0, 0}, Color{255, 0, 0}, Color{255, 0, 0} },
        { Color{0, 255, 0}, Color{0, 255, 0}, Color{0, 255, 0}, Color{0, 255, 0} },
        { Color{0, 0, 255}, Color{0, 0, 255}, Color{0, 0, 255}, Color{0, 0, 255} },
        { Color{255, 0, 255}, Color{255, 0, 255}, Color{255, 0, 255}, Color{255, 0, 255} }
    }};

    img.save_to_ppm("test.ppm");

    return 0;
}
