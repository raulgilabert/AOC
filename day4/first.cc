#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find(vector<string> data, int x, int y) {
    int counter = 0;
    if (data[x][y] == 'X') {
        if ((y+1 < data[x].size()) && data[x][y+1] == 'M')
            if ((y+2 < data[x].size()) && data[x][y+2] == 'A')
                if ((y+3 < data[x].size()) && data[x][y+3] == 'S')
                    counter++;
        if ((y-1 >= 0) && data[x][y-1] == 'M')
            if ((y-2 >= 0) && data[x][y-2] == 'A')
                if ((y-3 >= 0) && data[x][y-3] == 'S')
                    counter++;
        if ((x+1 < data.size()) && data[x+1][y] == 'M')
            if ((x+2 < data.size()) && data[x+2][y] == 'A')
                if ((x+3 < data.size()) && data[x+3][y] == 'S')
                    counter++;
        if ((x-1 >= 0) && data[x-1][y] == 'M')
            if ((x-2 >= 0) && data[x-2][y] == 'A')
                if ((x-3 >= 0) && data[x-3][y] == 'S')
                    counter++;
        if ((x+1 < data.size()) && (y+1 < data[x].size()) && data[x+1][y+1] == 'M')
            if ((x+2 < data.size()) && (y+2 < data[x].size()) && data[x+2][y+2] == 'A')
                if ((x+3 < data.size()) && (y+3 < data[x].size()) && data[x+3][y+3] == 'S')
                    counter++;
        if ((x-1 >= 0) && (y-1 >= 0) && data[x-1][y-1] == 'M')
            if ((x-2 >= 0) && (y-2 >= 0) && data[x-2][y-2] == 'A')
                if ((x-3 >= 0) && (y-3 >= 0) && data[x-3][y-3] == 'S')
                    counter++;
        if ((x+1 < data.size()) && (y-1 >= 0) && data[x+1][y-1] == 'M')
            if ((x+2 < data.size()) && (y-2 >= 0) && data[x+2][y-2] == 'A')
                if ((x+3 < data.size()) && (y-3 >= 0) && data[x+3][y-3] == 'S')
                    counter++;
        if ((x-1 >= 0) && (y+1 < data[x].size()) && data[x-1][y+1] == 'M')
            if ((x-2 >= 0) && (y+2 < data[x].size()) && data[x-2][y+2] == 'A')
                if ((x-3 >= 0) && (y+3 < data[x].size()) && data[x-3][y+3] == 'S')
                    counter++;
        return counter;
    } else {
        return 0;
    }
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