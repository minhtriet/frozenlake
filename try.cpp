#include <iostream>
#include <fstream>
#include <vector>

struct Point {
    int x;
    int y;
    Point(): x{0}, y{0} {
        std::cout << "default";
    }
    Point(int x_, int y_): x{x_}, y{y_} {
        std::cout << "cool " << x_ << " " << y_;
    }
};


// Read n and n points in a file
std::vector<Point> read_special_states(std::fstream& fp, ) {
    int n_states = 0;
    int temp_x, temp_y;
    for (auto& state : states) {
        fp >> temp_x >> temp_y;
        state.x = temp_x;
        state.y = temp_y;
    }
    return states;
}

int init_board(std::vector<Point>*& end_states, std::vector<Point>*& obstacles, std::vector<std::vector<float>>& board) {
    std::fstream fp("input.txt");
   
    int n_row, n_col;
    fp >> n_row >> n_col;
    
    int start_x, start_y;
    fp >> start_x >> start_y;
    Point start = {start_x, start_y};

    int n_states;
    fp >> n_states;
    std::vector<Point> states(n_states);
    
    end_states = &read_special_states(fp); 

    obstacles = &read_special_states(fp);

    std::vector<std::vector<float>> board(n_row, std::vector<float>(n_col));
    for (int i = 0; i < n_row; i++) {
        for (int j = 0; j < n_row; j++) {
            fp >> board[i][j];
        } 
    }
    return 0;
}


int main() {
    std::vector<Point>* end_states;
    std::vector<Point>* obstacles;
    std::vector<float>* board;
    init_board(end_states, obstacles, board);
    return 0;
}
