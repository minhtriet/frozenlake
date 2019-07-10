#include <fstream>
#include <vector>
#include <limits>
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
        fp >> board.best_value[board.end_states[i].x][board.end_states[i].y];
    }
    fp >> board.reward;
}


int main() {
    Point start_state;
    Board board;
    init_board(start_state, board);
    board.run();
    return 0;
}
