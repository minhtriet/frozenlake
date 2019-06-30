#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <map>

#include "Board.cpp"

template <typename T>
void print(const std::vector<std::vector<T>>& matrix) {
    for (int j=0; j < matrix[0].size(); j++) {
        for (int i=0; i < matrix.size(); i++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void read_special_states(std::fstream& fp, std::vector<Point>& states) {
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
    board.height = n_row;
    board.width = n_col;

    int start_x, start_y;
    fp >> start_x >> start_y;
    start_state.x = start_x;
    start_state.y = start_y;

    read_special_states(fp, board.end_states);
    read_special_states(fp, board.obstacles);
    for (int i = 0; i < board.end_states.size(); i++) {
        float temp_reward;
        fp >> temp_reward;
        board.end_reward.insert(std::pair<Point, float>(board.end_states[i], temp_reward));
    }
    fp >> board.reward;
}


int main() {
    Point start_state;
    Board board;
    init_board(start_state, board);
    // Save best result and best direction
    std::vector<std::vector<float>> best_value(board.width, std::vector<float>(board.height, 0));
    // Moving vector and its probabilities
    std::vector<std::vector<Point>> best_policy(board.width, std::vector<Point>(board.height, Point(0,0)));

    for (int iteration = 0; iteration < 1; iteration++) {
        for (int y = 0; y < board.height; y++) 
            for (int x = 0; x < board.width; x++) {
                float best_result = std::numeric_limits<float>::lowest();
                Point best_direction;
                for (auto direction : board.direction) {
                    float result = board.move(Point(x, y), direction, best_value, iteration);
                    if (best_result < result) {
                        best_result = result;
                        best_direction = direction;
                    }
                }
                best_value[x][y] = best_result;
                best_policy[x][y] = best_direction;
            }
    }
    print(best_value);
    print(best_policy);
    return 0;
}
