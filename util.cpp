#include<vector>

template typename<T>
bool is_in_vector(const T& location, const std::vector<T>& to_check) {
    if (std::find(to_check.begin(), to_check.end(), location) != to_check.end()) {
        return true;
    }
    return false;
}
