#pragma once

#include <ostream>


class Color
{
public:
    Color operator*(const double alpha) const;

public:
    uint8_t RED;
    uint8_t GREEN;
    uint8_t BLUE;
};

std::ostream& operator<<(std::ostream &out , const Color &color);
