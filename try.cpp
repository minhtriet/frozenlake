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
std::vector<Point> read_special_states(std::fstream fp) {
    int n_states = 0;
    int temp_x, temp_y;
    fp >> n_states;
    std::vector<Point> states(n_states);
    for (auto state : states) {
        fp >> temp_x >> temp_y;
        state = Point(temp_x, temp_y);
    }
    return states;
}

int init_board() {
    std::fstream fp("input.txt");
   
    int n_row, n_col;
    fp >> n_row >> n_col;
    
    int start_x, start_y;
    fp >> start_x >> start_y;
    Point start = {start_x, start_y};

    Point* end_states = read_special_states(fp); 

    Point* obstacles = read_special_states(fp);

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
                
    }
    return 0;
}


int main() {
    init_board();
    return 0;
}

