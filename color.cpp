#include "color.hpp"


std::ostream& operator<<(std::ostream &out , const Color &color)
{
    return out << "("  << (short) color.RED
               << ", " << (short) color.GREEN
               << ", " << (short) color.BLUE << ")";
}
