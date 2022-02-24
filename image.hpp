#pragma once

#include <vector>
#include <ostream>
#include "color.hpp"


class Image
{
public:
    void save_to_ppm(const std::string &filename) const;

public:
    int width;
    int height;
    std::vector<std::vector<Color>> buffer;
};
