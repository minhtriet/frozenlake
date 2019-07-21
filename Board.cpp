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
    if (direction.x == 0) {
        total_reward += move(current_loc, Point(-1, 0), this->probs[1]);
        total_reward += move(current_loc, Point(1, 0), this->probs[2]);
    }
    if (direction.y == 0) {
        total_reward += move(current_loc, Point(0, -1), this->probs[1]);
        total_reward += move(current_loc, Point(0, 1), this->probs[2]);
    }
    if (!util::is_in_vector(current_loc + direction, this->end_states)) {
        total_reward += Board::move(current_loc, direction, this->probs[0]);
        total_reward *= gamma;
        total_reward += this->reward;
    } else {
        total_reward *= gamma;
        total_reward += Board::move(current_loc, direction, this->probs[0]);
    }
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
        this->schedule.push(start_state);
        std::vector<Point> visited;
        while (this->schedule.size() > 0) {
            Point p = schedule.front();
            this->schedule.pop();
            visited.insert(visited.begin(), p);
            float result, best_result = std::numeric_limits<float>::lowest();
            Point best_direction;
            for (auto direction : direction) {
                Point new_loc = p + direction;
                if (this->is_inside(new_loc)) {
                    if (!util::is_in_vector(new_loc, visited) 
                            && (!util::is_in_vector(new_loc, obstacles))
                            && (!util::is_in_vector(new_loc, end_states))) {
                        schedule.push(new_loc);
                    }
                }
                result = move(p, direction);
                if (result > best_result) {
                    best_result = result;
                    best_direction = direction;
                }
            }
            best_value[p.x][p.y] = best_result;
            best_policy[p.x][p.y] = best_direction;
        }
        util::print<float>(best_value);
        util::print<Point>(best_policy);
    }
    return 0;
}
