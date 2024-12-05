#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find(vector<string> data, int x, int y) {
    int counter = 0;
    if (data[x][y] == 'A') {
        if ((y-1 >= 0) && (y+1 < data.size()) && (x-1 >= 0) && (x+1 < data[0].size())) {
            if (data[x+1][y+1] == 'M' && data[x-1][y-1] == 'S') {
                if (data[x-1][y+1] == 'M' && data[x+1][y-1] == 'S') {
                    counter++;
                }
                if (data[x-1][y+1] == 'S' && data[x+1][y-1] == 'M') {
                    counter++;
                }
            } else if (data[x+1][y+1] == 'S' && data[x-1][y-1] == 'M') {
                if (data[x-1][y+1] == 'M' && data[x+1][y-1] == 'S') {
                    counter++;
                }
                if (data[x-1][y+1] == 'S' && data[x+1][y-1] == 'M') {
                    counter++;
                }
            }
        }
    }
    return counter;
}


int main() {
    vector<string> data;

    string line;

    while (getline(cin, line)) {
        data.push_back(line);
    }

    int counter = 0;

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            counter += find(data, i, j);
        }
    }

    cout << counter << endl;
}