#include <vector>
#include <iostream>
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
    // edge cases
    if (util::is_in_vector(current_loc, this->obstacles)) {
        return 0;
    }
    if (util::is_in_vector(current_loc, this->end_states)) {
        return this->end_reward[current_loc];
    }
    if (util::is_in_vector(current_loc, visited)) {
        return std::numeric_limits<float>::lowest();
    }
    // push new points to visit schedule
    Point new_loc = current_loc + direction;
    if (!util::is_in_vector(new_loc, visited) && (this->is_inside(new_loc))
            && (!util::is_in_vector(new_loc, this->obstacles))
            && (!util::is_in_vector(new_loc, this->end_states))) {
        this->schedule.push(new_loc);
        this->step[new_loc] = this->step.find(current_loc)->second + 1;
    }
    // calculate reward
    int timestep = this->step.find(current_loc)->second;
    float total_reward = 0;
    if (direction.x == 0) {
        total_reward += move(current_loc, Point(-1, 0), timestep, this->probs[1]);
        total_reward += move(current_loc, Point(1, 0), timestep, this->probs[2]);
    }
    if (direction.y == 0) {
        total_reward += move(current_loc, Point(0, -1), timestep, this->probs[1]);
        total_reward += move(current_loc, Point(0, 1), timestep, this->probs[2]);
    }
    total_reward += Board::move(current_loc, direction, timestep, this->probs[0]);
    return total_reward;
}

float Board::move(const Point& current_loc, const Point& direction, 
        int timestep, float prob) {
    float total_reward = 0;
    Point new_loc = current_loc + direction;
    total_reward = this->reward;
    // edge cases
    if (util::is_in_vector(new_loc, this->obstacles)) {
        return total_reward + prob * std::pow(this->gamma, timestep) * 
            this->best_value[current_loc.x][current_loc.y];
    }
    if (util::is_in_vector(new_loc, this->end_states)) {
        return total_reward + prob * this->end_reward[new_loc];
    }
    // end of edges cases
    if (this->is_inside(new_loc)) {
        return total_reward + prob * std::pow(this->gamma, timestep) * 
            this->best_value[new_loc.x][new_loc.y];
    } else {
        return total_reward + prob * std::pow(this->gamma, timestep) * 
            this->best_value[current_loc.x][current_loc.y];
    }
}

int Board::run() {
    while (this->schedule.size() > 0) {
        float best_result = std::numeric_limits<float>::lowest();
        Point best_direction;
        Point p = schedule.front();
        for (auto direction : this->direction) {
            float result = this->move(p, direction);
            if (best_result < result) {
                best_result = result;
                best_direction = direction;
            }
        }
        this->best_value[p.x][p.y] = best_result;
        this->best_policy[p.x][p.y] = best_direction;
        this->visited.insert(this->visited.begin(), p);
        this->schedule.pop();
    }
    return 0;
}
