#pragma once

#include <ostream>


class Color
{
public:
    short RED;
    short GREEN;
    short BLUE;
};

std::ostream& operator<<(std::ostream &out , const Color &color);
