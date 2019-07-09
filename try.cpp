#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
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

    fp >> start_state.x >> start_state.y;
    board.init(start_state); 
    board.best_value = std::vector(n_col, 
            std::vector<float>(n_row, std::numeric_limits<float>::lowest()));
    board.best_policy = std::vector(n_col, std::vector<Point>(n_row, Point(0,0)));
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
    board.run();
    print(board.best_value);
    print(board.best_policy); 
    return 0;
}
