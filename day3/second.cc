#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <sstream>

using namespace std;

vector<string> read_data(string file_name) {
    ifstream file(file_name);

    vector<string> data;

    string line;

    while (getline(file, line)) {
        data.push_back(line);
    }

    file.close();

    return data;
}


int main() {
    vector<string> data = read_data("input.txt");

    int accumulator = 0;

    bool enable = true;

    for (string line: data) {
        regex re(R"(mul\(\d+,\d+\)|do\(\)|don't\(\))");

        auto start = sregex_iterator(line.begin(), line.end(), re);
        auto end = sregex_iterator();

        for (sregex_iterator it = start; it != end; ++it) {
            smatch match = *it;

            if (match.str() == "do()") {
                enable = true;
            } else if (match.str() == "don't()") {
                enable = false;
            } else if (enable) {
                stringstream ss(match.str());

                char a;

                int left, right;

                ss >> a >> a >> a >> a >> left >> a >> right;

                accumulator += left*right;
            }
        }
    }

    cout << accumulator << endl;
}
