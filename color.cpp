#include "color.hpp"

#include <algorithm>


Color Color::operator*(const double alpha) const // TODO: pass to HSL for cleaner color convertion
{
    return Color{static_cast<uint8_t>(std::min(RED * alpha, 255.0)),
                 static_cast<uint8_t>(std::min(GREEN * alpha, 255.0)),
                 static_cast<uint8_t>(std::min(BLUE  * alpha, 255.0))};
}

std::ostream& operator<<(std::ostream &out , const Color &color)
{
    return out << "("  << (short) color.RED
               << ", " << (short) color.GREEN
               << ", " << (short) color.BLUE << ")";
}
