#include <iostream>
#include <fstream>

def init_board() {
    std::ifstream infile("input.txt");
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        int a, b;
        if (!(iss >> a >> b)) { break; } // error

        // process pair (a,b)
    }
    while (std::getline(infile, line)
    return board
}


int main() {
    std::cout << "Hello";
    return 0;
}

