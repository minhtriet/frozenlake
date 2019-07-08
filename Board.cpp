#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include "util.cpp"
#include "Board.h"


void Board::init(const Point& start_state) {
    this->schedule.push(start_state);
    this->step.insert(std::pair<Point, int>(start_state, 0));
}

bool Board::is_inside(const Point& location) {
    if ((location.x >= 0) && (location.y >= 0) \
       && (location.x < this->width) && (location.y < this->height))
        return true;
     return false;
}

float Board::move(const Point& current_loc, const Point& direction) {
    if (util::is_in_vector(current_loc, this->obstacles)) {
        return 0;
    }
    if (util::is_in_vector(current_loc, this->end_states)) {
        return this->end_reward[current_loc];
    }
    if (util::is_in_vector(current_loc, visited)) {
        return std::numeric_limits<float>::lowest();
    }
    int timestep = this->step.find(current_loc)->second;
    return Board::move(current_loc, direction, timestep, this->probs[0]);
}

float Board::move(const Point& current_loc, const Point& direction, 
        int timestep, float prob) {
    float total_reward = 0;
    if (std::abs(prob - this->probs[0]) < 0.0001) {  // 1st move
        total_reward = this->reward;
        if (direction.x == 0) {
            total_reward += move(current_loc, Point(-1, 0), timestep, this->probs[1]);
            total_reward += move(current_loc, Point(1, 0), timestep, this->probs[2]);
        }
        if (direction.y == 0) {
            total_reward += move(current_loc, Point(0, -1), timestep, this->probs[1]);
            total_reward += move(current_loc, Point(0, 1), timestep, this->probs[2]);
        }
    }
    Point new_loc = current_loc + direction;
    if (util::is_in_vector(new_loc, this->obstacles)) {
        return total_reward + prob * std::pow(this->gamma, timestep) * 
            this->best_value[current_loc.x][current_loc.y];
    }
    if (util::is_in_vector(new_loc, this->end_states)) {
        return total_reward + prob * this->end_reward[new_loc];
    }
    if (this->is_inside(new_loc)) {
        this->schedule.push(new_loc);
        this->step[new_loc] = this->step.find(current_loc)->second + 1;
        return total_reward + prob * std::pow(this->gamma, timestep) * 
            this->best_value[new_loc.x][new_loc.y];
    } else {
        return total_reward + prob * std::pow(this->gamma, timestep) * 
            this->best_value[current_loc.x][current_loc.y];
    }
}

int Board::run() {
    while (this->schedule.size() > 0) {
        for (auto direction : this->direction) {
            reward = this->move(schedule.front(), direction);
        }
        this->visited.insert(this->visited.begin(), schedule.front());
        this->schedule.pop();
    }
    return 0;
}
