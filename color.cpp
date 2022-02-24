#include "color.hpp"


std::ostream& operator<<(std::ostream &out , const Color &color)
{
    return out << "(" << color.RED << ", " << color.GREEN << ", " << color.BLUE << ")";
}
