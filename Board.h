#include <vector>
#include <map>

#include "Point.cpp"

class Board {
    private:
        bool is_inside(Point& location);
        bool is_in_vector(const Point& location, const std::vector<Point>& to_check);
    public:
        int width;
        int height;
        std::vector<Point> direction{Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)};
        std::vector<Point> end_states;
        std::map<Point, float> end_reward;
        std::vector<Point> obstacles;
        float reward;
        float gamma{0.9};
        float move(const Point& current_loc, const Point& direction, const std::vector<std::vector<float>> &value);
        float move(const Point& current_loc, const Point& direction, const std::vector<std::vector<float>> &value, float prob);
        const std::vector<float> probs{0.8, 0.1, 0.1};
}; 

