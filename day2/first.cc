#include <iostream>
#include <vector>
#include <sstream>

bool is_safe(std::vector<int> numbers) {
    bool increasing;

    if (numbers[0] < numbers[1]) {
        increasing = true;
    } else {
        increasing = false;
    }

    bool safe = true;

    for (size_t i = 1; safe and (i < numbers.size()); i++) {
        safe = (numbers[i - 1] != numbers[i] and (
                (increasing and (numbers[i - 1] < numbers[i]) and ((numbers[i] - numbers[i - 1]) <= 3)) or
                (!increasing and (numbers[i - 1] > numbers[i]) and ((numbers[i - 1] - numbers[i]) <= 3))));
    }

    return safe;
}


int main() {
    std::string line;

    int qtt_safe = 0;

    while (std::getline(std::cin, line)) {
        std::vector<int> numbers;

        std::stringstream iss(line);

        int num;

        while (iss >> num) {
            numbers.push_back(num);
        }

        if (is_safe(numbers)) {
            qtt_safe++;
        }
    }

    std::cout << qtt_safe << std::endl;
}