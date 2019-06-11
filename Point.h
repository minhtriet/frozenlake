#pragma once

struct Point {
    int x;
    int y;
    public:
        Point();
        Point(int x_, int y_);
        Point operator+(const Point& p1);
};
