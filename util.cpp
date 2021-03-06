#include<vector>
#include <iostream>
#include <iomanip>
#include <type_traits>
#include <limits>

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
            std::cout << std::setprecision(3) << std::fixed;
            for (int j=0; j < matrix[0].size(); j++) {
                for (int i=0; i < matrix.size(); i++) {
                    if (matrix[i][j] == std::numeric_limits<T>::lowest()) {
                        std::cout << "✗  ";
                        continue;
                    }
                    std::cout << matrix[i][j] << "  ";
                }
                std::cout << "\n";
            }
        }
}
