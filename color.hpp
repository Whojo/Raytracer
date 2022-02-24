#pragma once

#include <ostream>


class Color
{
public:
    uint8_t RED;
    uint8_t GREEN;
    uint8_t BLUE;
};

std::ostream& operator<<(std::ostream &out , const Color &color);
