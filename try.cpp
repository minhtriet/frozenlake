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
               && (location.x < self.width) && (location.y < self.height):
                return true;
             return false;
        } 
        
    public:
        int width;
        int height;
        std::vector<float> probs = [0.8, 0.1, 0.1];
        std::vector<Point> direction = [Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)];
        std::vector<Point> end_states;
        std::vector<Point> obstacles;
        float reward;


        bool move(Point& current_location, Point& direction, float& reward, prob=probs[0]) {
            if prob == probs[0] {
                std::vector<float> temp_reward(3);
                if (direction.x) == 0 {
                    // move to direction x with 0.1 probs
                    move(current_location, Point(-1, direction.y), float& temp_reward[1], probs[1]);
                    move(current_location, Point(1, direction.y), float& temp_reward[2], probs[2]);
                }
                if (direction.y == 0) {
                    // move to direction x with 0.1 probs
                    move(current_location, Point(direction.x, -1), float& temp_reward[1], probs[1]);
                    move(current_location, Point(direction.x, 1 ), float& temp_reward[2], probs[2]);
                }
            }
            Point new_position = current_location + direction;
        }
}    


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

void init_board(Point& start_state, std::vector<Point>& end_states, std::vector<Point>& obstacles, std::vector<std::vector<float>>& board) {
    std::fstream fp("input.txt");

    int n_row, n_col;
    fp >> n_row >> n_col;

    int start_x, start_y;
    fp >> start_x >> start_y;
    start_state.x = start_x;
    start_state.y = start_y;

    read_special_states(fp, end_states);

    read_special_states(fp, obstacles);

    board.resize(n_row, std::vector<float>(n_col));
    for (int i = 0; i < n_row; i++) {
        for (int j = 0; j < n_col; j++) {
            fp >> board[i][j];
        }
    }
}

void calculate(std::vector<std::vector<float>>& board, std::vector<Point>& direction, std::vector<std::vector<float>>& u) {
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].size(); j++) {
            float temp_reward, best_reward = std::numeric_limits<float>::min();
            int best_direction = 
            for (int d = 0; d < direction.size(); d++) {
                int temp_i = i - direction[d].y;
                int temp_j = j - direction[d].x;
                temp_reward = board[temp_i, temp_j]*probs[d];
            }
        } 
}


int main() {
    Point start_state;
    std::vector<Point> end_states;
    std::vector<Point> obstacles;
    std::vector<std::vector<float>> board;
    init_board(start_state, end_states, obstacles, board);
    
    // Moving vector and its probabilities
    //

    std::vector<std::vector<float>> u;
    calculate(board, u, p_forward, p_backward, p_right, p_left); 
    return 0;
}

