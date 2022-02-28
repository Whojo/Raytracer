#include "color.hpp"

#include <algorithm>


Color Color::operator*(const double alpha) const // TODO: pass to HSL for cleaner color convertion
{
    return Color{static_cast<uint16_t>(std::min(RED * alpha, 255.0)),
                 static_cast<uint16_t>(std::min(GREEN * alpha, 255.0)),
                 static_cast<uint16_t>(std::min(BLUE  * alpha, 255.0))};
}

static uint16_t add_color_canal(const uint16_t i1, const uint16_t i2)
{
    auto max = std::max(i1, i2);
    auto min = std::min(i1, i2);

    return max + (min / 255.0) * (255 - max) / 2;
}

Color Color::operator*(const Color &c) const
{
    return Color{ add_color_canal(RED, c.RED),
                  add_color_canal(GREEN, c.GREEN),
                  add_color_canal(BLUE, c.BLUE)};
}

Color Color::operator+(const Color &c) const
{
    return Color{ static_cast<uint16_t>(RED + c.RED),
                  static_cast<uint16_t>(GREEN + c.GREEN),
                  static_cast<uint16_t>(BLUE + c.BLUE) };
}

Color Color::operator/(const double alpha) const
{
    return Color{ static_cast<uint16_t>(RED / alpha),
                  static_cast<uint16_t>(GREEN / alpha),
                  static_cast<uint16_t>(BLUE / alpha) };
}

std::ostream& operator<<(std::ostream &out , const Color &color)
{
    return out << "("  << (short) color.RED
               << ", " << (short) color.GREEN
               << ", " << (short) color.BLUE << ")";
}
