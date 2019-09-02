#include <vector>
#include <iostream>
#include <algorithm>
#include "Board.h"
#include "util.cpp"


bool Board::is_inside(const Point& location) {
    if ((location.x >= 0) && (location.y >= 0) \
            && (location.x < this->width) && (location.y < this->height))
        return true;
    return false;
}

float Board::move(const Point& current_loc, const Point& direction) {
    float total_reward = 0;
    // given a move, return total reward
    return total_reward;
}

float Board::move(const Point& current_loc, const Point& direction, 
        float prob) {
    Point new_loc = current_loc + direction;
    // edge cases
    if (util::is_in_vector(new_loc, this->obstacles) || !is_inside(new_loc)) {
        return prob * best_value[current_loc.x][current_loc.y];
    }
    if (util::is_in_vector(new_loc, this->end_states)) {
        return prob * best_value[new_loc.x][new_loc.y];
    }
    // end of edges cases
    return prob * this->best_value[new_loc.x][new_loc.y];
}

int Board::run() {
    for (int i = 0; i < 10; i++) {
        // BFS _logic
        util::print<float>(best_value);
        util::print<Point>(best_policy);
    }
    return 0;
}
