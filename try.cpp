#include <iostream>
#include <fstream>
#include <vector>

struct Point {
    int x;
    int y;
    Point(): x{0}, y{0} {}
    Point(int x_, int y_): x{x_}, y{y_} {}
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

void calculate(std::vector<std::vector<float>>& board, std::vector<Point>& direction) {
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].size(); j++) {
            for (int d = 0; direction < d.size()) {
                u[i,j] = board[i,j] + alpha*u[i,j];
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
    std::vector<float> probs = [0.8, 0.0, 0.1, 0.1];

    std::vector<std::vector<float>> u;
    calculate(board, u, p_forward, p_backward, p_right, p_left); 
    return 0;
}

