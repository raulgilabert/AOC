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
    size_t right_it = 0;

    for (size_t i = 0; i < left_numbers.size(); i++) {
        while (right_numbers[right_it] < left_numbers[i]) {
            right_it++;

            if (right_it == right_numbers.size()) {
                break;
            }
        }

        int current_right_it = right_it;

        int times = 0;

        while (right_numbers[right_it] == left_numbers[i]) {
            times++;
            right_it++;
        }

        accumulator += std::abs(left_numbers[i] * times);

        right_it = current_right_it;
    }

    std::cout << accumulator << std::endl;
}