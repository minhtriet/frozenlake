#include <vector>
#include <map>
#include <queue>
#include "Point.cpp"

class Board {
    private:
        bool is_inside(const Point& location);
        std::queue<Point> schedule;
        std::vector<Point> visited;
        std::map<Point, int> step;
    public:
        std::vector<std::vector<float>> best_value;
        std::vector<std::vector<Point>> best_policy;
        int width;
        int height;
        std::vector<Point> direction{Point(1, 0), Point(0, 1), 
            Point(-1, 0), Point(0, -1)};
        std::vector<Point> end_states;
        std::map<Point, float> end_reward;
        std::vector<Point> obstacles;
        float reward;
        float gamma{0.9};
        float move(const Point& current_loc, const Point& direction);
        float move(const Point& current_loc, const Point& direction, 
                int timestep, float prob);
        const std::vector<float> probs{0.8, 0.1, 0.1};
        void init(const Point& start_state);
        int run();
}; 

