#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::vector<int> left_numbers;
    std::vector<int> right_numbers;

    int left, right;

    while (std::cin >> left >> right) {
        left_numbers.push_back(left);
        right_numbers.push_back(right);
    }

    sort(left_numbers.begin(), left_numbers.end());
    sort(right_numbers.begin(), right_numbers.end());

    int accumulator = 0;

    for (int i = 0; i < left_numbers.size(); i++) {
        accumulator += std::abs(left_numbers[i] - right_numbers[i]);
    }

    std::cout << accumulator << std::endl;
}