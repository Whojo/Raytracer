#include "image.hpp"

#include <fstream>


void Image::save_to_ppm(const std::string &filename) const
{
    std::ofstream f(filename);
    f << "P3" << std::endl
      << width << " " << height << std::endl
      << 255 << std::endl;

    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            f << " " << (short) buffer[i][j].RED
              << " " << (short) buffer[i][j].GREEN
              << " " << (short) buffer[i][j].BLUE
              << " " << std::endl;
        }
    }

    f.close();
}
