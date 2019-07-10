#include <ostream>

struct Point {
    int x;
    int y;
    public:
        Point();
        Point(int x_, int y_);
        std::ostream operator<<(const Point& p) ;
};
