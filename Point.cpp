#include "Point.h"

Point::Point(): x{0}, y{0} {}
Point::Point(int x_, int y_): x{x_}, y{y_} {}
std::ostream &operator<<(std::ostream& os, const Point& p) {
    if (p.x == 1 && p.y == 0) return os << "→ ";
    if (p.x == -1 && p.y == 0) return os << "← ";
    if (p.x == 0 && p.y == 1) return os <<  "↑ ";
    if (p.x == 0 && p.y == -1) return os << "↓ ";
    if (p.x == 0 && p.y == 0) return os << "✗ ";
    return os << "(" << p.x << ";" << p.y << ")";
}
