#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

enum Cell {
    CLEAR = '.',
    OBSTACLE = '#',
    VISITED = 'X'
};

typedef vector<Cell> VC;
typedef vector<VC> VVC;
struct Pos {
    int x, y;
};
enum Direction {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

Pos calc_next_pos(Pos player, Direction dir) {
    Pos next_pos = player;

    switch (dir) {
        case UP: {
            next_pos.y--;
            break;
        }
        case DOWN: {
            next_pos.y++;
            break;
        }
        case LEFT: {
            next_pos.x--;
            break;
        }
        case RIGHT: {
            next_pos.x++;
            break;
        }
    }

    return next_pos;
}

Direction rotate(Direction dir) {
    Direction new_dir;
    switch (dir) {
        case UP: {
            new_dir = RIGHT;
            break;
        }
        case RIGHT: {
            new_dir = DOWN;
            break;
        }
        case DOWN: {
            new_dir = LEFT;
            break;
        }
        case LEFT: {
            new_dir = UP;
            break;
        }
    }

    return new_dir;
}

int main() {
    VVC map;
    Pos player;
    Direction dir;

    int x = 0;
    int y = 0;

    string line;

    while (getline(cin, line)) {
        char tile;

        stringstream ss(line);

        VC line_map(line.size(), CLEAR);

        while (ss >> tile) {
            if (tile == '#') {
                line_map[x] = OBSTACLE;
            } else if (tile == 'v') {
                player.x = x;
                player.y = y;

                dir = DOWN;
                line_map[x] = VISITED;
            } else if (tile == '^') {
                player.x = x;
                player.y = y;

                dir = UP;
                line_map[x] = VISITED;
            } else if (tile == '>') {
                player.x = x;
                player.y = y;

                dir = RIGHT;
                line_map[x] = VISITED;
            } else if (tile == '<') {
                player.x = x;
                player.y = y;

                dir = LEFT;
                line_map[x] = VISITED;
            }

            x++;
        }
        x = 0;
        map.push_back(line_map);
        y++;
    }

    for (auto line : map) {
        for (auto c : line) {
            cout << c;
        }
        cout << endl;
    }

    bool inside = true;
    int counter = 1;

    while (inside) {
        Pos next_pos = calc_next_pos(player, dir);

        inside = (next_pos.x >= 0) and (next_pos.x < map[0].size()) and (next_pos.y >= 0) and (next_pos.y < map.size());

        if (inside) {
            while (map[next_pos.y][next_pos.x] == OBSTACLE) {
                dir = rotate(dir);
                next_pos = calc_next_pos(player, dir);

                inside = (next_pos.x >= 0) and (next_pos.x < map[0].size()) and (next_pos.y >= 0) and (next_pos.y < map.size());
            }

            if (map[next_pos.y][next_pos.x] == CLEAR) {
                map[next_pos.y][next_pos.x] = VISITED;
                counter++;
            }

            player = next_pos;
        }
    }

    for (auto line : map) {
        for (char c : line) {
            cout << c;
        }
        cout << endl;
    }


    cout << counter << endl;
}