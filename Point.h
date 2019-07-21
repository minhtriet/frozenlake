#include <ostream>

struct Point {
    int x;
    int y;
	Point();
	Point(int x_, int y_);
	std::ostream operator<<(const Point& p) ;
};
