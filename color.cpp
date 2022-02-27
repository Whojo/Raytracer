#include "color.hpp"


Color Color::operator*(const double alpha) const // TODO: pass to HSL for cleaner color convertion
{
    return Color{static_cast<uint8_t>(RED   * alpha),
                 static_cast<uint8_t>(GREEN * alpha),
                 static_cast<uint8_t>(BLUE  * alpha)};
}

std::ostream& operator<<(std::ostream &out , const Color &color)
{
    return out << "("  << (short) color.RED
               << ", " << (short) color.GREEN
               << ", " << (short) color.BLUE << ")";
}
