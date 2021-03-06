#include <fstream>
#include <vector>
#include <limits>
#include "Board.cpp"


void read_special_states(std::fstream& fp, std::vector<Point>& states, Board& board) {
    int n_states;
    int temp_x, temp_y;
    fp >> n_states;
    states.resize(n_states);
    for (auto& state : states) {
        fp >> temp_x >> temp_y;
        state.x = temp_x;
        state.y = temp_y;
        board.best_policy[temp_x][temp_y] = Point(0,0);
        board.best_value[temp_x][temp_y] = std::numeric_limits<float>::lowest();
    }
}

void init_board(Board& board, char *filename) {
    std::fstream fp(filename);

    int n_row, n_col;
    fp >> n_row >> n_col;
    board.height = n_row;
    board.width = n_col;

    fp >> board.start_state.x >> board.start_state.y;
    fp >> board.reward;
    board.best_value = std::vector(n_col, std::vector<float>(n_row, board.reward));
    // init to a random value to discourage staying in the same place
    board.best_policy = std::vector(n_col, std::vector<Point>(n_row, Point(0,1)));
    read_special_states(fp, board.end_states, board);
    read_special_states(fp, board.obstacles, board);
    for (auto i : board.end_states) {
        fp >> board.best_value[i.x][i.y];
    }
}


int main(int argc, char *argv[]) {
    Board board;
    init_board(board, argv[1]);
    board.run();
    return 0;
}
