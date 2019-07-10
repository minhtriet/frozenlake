#include<vector>
#include <iostream>
#include <iomanip>

namespace util {

    template <typename T> 
        bool is_in_vector(const T& location, const std::vector<T>& to_check) {
            if (std::find(to_check.begin(), to_check.end(), location) 
                    != to_check.end()) {
                return true;
            }
            return false;
        }

    template <typename T> 
        void print(const std::vector<std::vector<T>>& matrix) {
            for (int j=0; j < matrix[0].size(); j++) {
                for (int i=0; i < matrix.size(); i++) {
                    std::cout << std::setprecision(5) << matrix[i][j] << " ";
                }
                std::cout << "\n";
            }
        }

    Point operator+(const Point& p0, const Point& p1) {
        return Point(p1.x + p0.x, p1.y + p0.y);
    }
    bool operator==(const Point& p0, const Point& p1) {
        return (p1.x == p0.x) && (p1.y == p0.y);
    }
    bool operator<(const Point& p0, const Point& p1) {
        return (p1.x < p0.x) || (p1.y < p0.y);
    }
}
