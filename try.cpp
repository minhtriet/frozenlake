#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <map>

#include "Board.cpp"

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

