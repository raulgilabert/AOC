#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<int, set<int>> depends_on;


bool sort_order(int a, int b) {
    set<int> dependencies_of = depends_on[a];
    return (dependencies_of.find(b) == dependencies_of.end());
}

int main() {

    string line;

    while (getline(cin, line) && line != "") {
        int left, right;
        char a;

        stringstream ss(line);
        ss >> left >> a >> right;

        depends_on[right].insert(left);
    }

    int accumulator = 0;

    while (getline(cin, line)) {
        stringstream ss(line);
        int num;
        vector<int> data_line;

        while (ss >> num) {
            data_line.push_back(num);

            char a;
            if (!(ss >> a)) {
                break;
            }
        }

        bool correct = true;

        for (int i = 0; correct and (i < data_line.size()); ++i) {
            set<int> dependencies_of = depends_on[data_line[i]];
            for (int j = 0; correct and (j < i); ++j) {
                if (dependencies_of.find(data_line[j]) == dependencies_of.end()) {
                    correct = false;
                }
            }
        }

        if (!correct) {
            sort(data_line.begin(), data_line.end(), sort_order);

            accumulator += data_line[data_line.size()/2];
        }
    }

    cout << accumulator << endl;
}