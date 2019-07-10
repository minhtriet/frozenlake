#include <iostream>
#include <queue>
#include "Point.cpp"
#include "util.cpp"

int main() {
    std::queue<Point> schedule;

    schedule.push(Point(1,2));
    schedule.push(Point(3,4));
    Point u = Point(1,3);
    Point v = Point(3,4);
    Point z = u + v;
    std::cout << z << '\n';
    Point t = schedule.front() + u;
    std::cout << t << '\n';
    return 0;
}
