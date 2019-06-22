#include <vector>
#include <map>

#include "Point.cpp"

class Board {
    private:
        bool is_inside(Point& location);
        int is_in_vector(const Point& location, const std::vector<Point>& to_check);
        const std::vector<float> probs{0.8, 0.1, 0.1};
    public:
        int width;
        int height;
        std::vector<Point> direction{Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)};
        std::vector<Point> end_states;
        std::map<Point, float> end_reward;
        std::vector<Point> obstacles;
        float reward;
        float move(const Point& current_loc, const Point& direction, float prob=0.8);
}; 

