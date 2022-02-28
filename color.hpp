#pragma once

#include <ostream>


class Color
{
public:
    Color operator*(const double alpha) const;
    Color operator*(const Color &c) const;
    Color operator+(const Color &c) const;
    Color operator/(const double alpha) const;

public:
    uint16_t RED;
    uint16_t GREEN;
    uint16_t BLUE;
};

std::ostream& operator<<(std::ostream &out , const Color &color);
