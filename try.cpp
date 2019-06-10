#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <map>

struct Point {
    int x;
    int y;
    Point(): x{0}, y{0} {}
    Point(int x_, int y_): x{x_}, y{y_} {}
    Point operator+(const Point& p1) {
        return Point(p1.x + this->x, p1.y + this->y);
    }
};

class Board {
    private:
        bool is_inside(Point& location) {
            if (location.x > 0) && (location.y > 0) \
               && (location.x < self.width) && (location.y < self.height)
                return true;
             return false;
        }
        
        bool is_end_state(Point& location) {
            std::find(this->end_reward.begin(), this->end_reward.end(), location);
            return false;
        } 
        
    public:
        int width;
        int height;
        const std::vector<float> probs{0.8, 0.1, 0.1};
        std::vector<Point> direction{Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)};
        std::vector<Point> end_states;
        std::map<Point, float> end_reward;
        std::vector<Point> obstacles;
        float reward;

        /**
            @param location and move
            @return reward of that move
        */
        float move(Point& current_loc, Point& direction, prob=this->probs[0]) {
            float total_reward = 0;
            if (prob == probs[0]) {
                if (direction.x == 0) {
                    // move to direction x with 0.1 probs
                    total_reward += move(current_loc, Point(-1, direction.y), this->probs[1]);
                    total_reward += move(current_loc, Point(1, direction.y), this->probs[2]);
                }
                if (direction.y == 0) {
                    // move to direction x with 0.1 probs
                    total_reward += move(current_loc, Point(direction.x, -1), this->probs[1]);
                    total_reward += move(current_loc, Point(direction.x, 1), this->probs[2]);
                }
            }
            Point new_loc = current_loc + direction;
            if (!this->is_inside(new_loc)) {
                return 0;
            }
            if (this->is_obstacle(new_loc)) {
                return 0;
            }
            if (this->is_end_state(new_loc)) {
                return 0;
            }
            return prob*reward;
        }
}; 


// Read n and n points in a file
void read_special_states(std::fstream& fp, std::vector<Point>& states ) {
    int n_states;
    int temp_x, temp_y;
    fp >> n_states;
    states.resize(n_states);
    for (auto& state : states) {
        fp >> temp_x >> temp_y;
        state.x = temp_x;
        state.y = temp_y;
    }
}

void init_board(Point& start_state, Board& board) {
    std::fstream fp("input.txt");

    int n_row, n_col;
    fp >> n_row >> n_col;

    int start_x, start_y;
    fp >> start_x >> start_y;
    start_state.x = start_x;
    start_state.y = start_y;

    read_special_states(fp, board.end_states);
    read_special_states(fp, board.obstacles);
    for (int i = 0; i < board.end_states.size(); i++) {
        float temp_reward;
        fp >> temp_reward;
        board.end_reward.insert(std::pair<board.end_states[i], temp_reward>);
    }
    fp >> board.reward;
}

void calculate(const Point& start, const Board& board) {
    
}


int main() {
    Point start_state;
    Board board;
    init_board(start_state, board);
    
    // Moving vector and its probabilities
    calculate(start_state, board);
    return 0;
}

