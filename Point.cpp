#include "Point.h"

Point::Point(): x{0}, y{0} {}
Point::Point(int x_, int y_): x{x_}, y{y_} {}
Point operator+(const Point& p0, const Point& p1) {
    return Point(p1.x + p0.x, p1.y + p0.y);
}
bool operator==(const Point& p0, const Point& p1) {
    return (p1.x == p0.x) && (p1.y == p0.y);
}
bool operator<(const Point& p0, const Point& p1) {
    return (p1.x < p0.x) || (p1.y < p0.y);
}
std::ostream &operator<<(std::ostream& os, const Point& p) {
    if (p.x == 1 && p.y == 0) return os << "→ ";
    if (p.x == -1 && p.y == 0) return os << "← ";
    if (p.x == 0 && p.y == 1) return os <<  "↑ ";
    return os <<  "↓ ";
}
