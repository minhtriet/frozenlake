#include "Point.h"

Point::Point(): x{0}, y{0} {}
Point::Point(int x_, int y_): x{x_}, y{y_} {}
Point operator+(const Point& p0, const Point& p1) {
    return Point(p1.x + p0.x, p1.y + p0.y);
}
bool operator==(const Point& p0, const Point& p1) {
    return (p1.x == p0.x) && (p1.y == p0.y);
}
