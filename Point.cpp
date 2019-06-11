#include "Point.h"

Point::Point(): x{0}, y{0} {}
Point::Point(int x_, int y_): x{x_}, y{y_} {}
Point::Point operator+(const Point& p1) {
    return Point(p1.x + this->x, p1.y + this->y);
}
